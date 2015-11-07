return class {
    __init__ = function(self, material) {
        resMgr = getResMgr();
        
        self.smoothness = 0.5;
        self.metalMask = 0.0;
        self.parallaxStrength = 0.0;
        self.parallaxEdgeDiscard = false;
        self.albedo = Float4(1.0);
        self.pomMinLayers = 8;
        self.pomMaxLayers = 32;
        self.minTessLevel = 1.0;
        self.maxTessLevel = 10.0;
        self.tessMinDistance = 0.0;
        self.tessMaxDistance = 10.0;
        self.displacementStrength = 0.1;
        self.displacementMidlevel = 0.5;
        self.shadowTesselation = false;
        self.shadowMinTessLevel = 1.0;
        self.shadowMaxTessLevel = 5.0;
        self.materialMap = nil;
        self.albedoMap = nil;
        self.normalMap = nil;
        self.parallaxHeightMap = nil;
        self.pomHeightMap = nil;
        self.displacementMap = nil;
        
        vertex = resMgr:loadShader("resources/shaders/object.vs.bin");
        fragment = resMgr:loadShader("resources/shaders/gbuffer.fs.bin");
        
        self.shaders = GfxShaderCombination(vertex, fragment);
        
        self.shadersAnim = GfxShaderCombination(vertex, fragment);
        self.shadersAnim:setDefine(GfxShaderType.Vertex, "SKELETAL_ANIMATION", "1");
        
        material.forward = false;
    };
    __del__ = function(self) {};
    
    load = function(self, file)
    {
        albedo = Float4();
        albedo.x = file:readFloat32();
        albedo.y = file:readFloat32();
        albedo.z = file:readFloat32();
        albedo.w = file:readFloat32();
        self.albedo = albedo;
        
        self.smoothness = file:readFloat32();
        self.metalMask = file:readFloat32();
        self.parallaxStrength = file:readFloat32();
        self.parallaxEdgeDiscard = file:readUInt8() != 0;
        self.pomMinLayers = file:readUInt8();
        self.pomMaxLayers = file:readUInt8();
        self.minTessLevel = file:readFloat32();
        self.maxTessLevel = file:readFloat32();
        self.tessMinDistance = file:readFloat32();
        self.tessMaxDistance = file:readFloat32();
        self.displacementStrength = file:readFloat32();
        self.displacementMidlevel = file:readFloat32();
        self:setAlbedoMap(self.readTexture(file));
        self:setMaterialMap(self.readTexture(file));
        self:setNormalMap(self.readTexture(file));
        self:setParallaxHeightMap(self.readTexture(file));
        self:setPOMHeightMap(self.readTexture(file));
        self:setDisplacementMap(self.readTexture(file));
    };
    
    save = function(self, file) {
        file:writeFloat32(self.albedo.x);
        file:writeFloat32(self.albedo.y);
        file:writeFloat32(self.albedo.z);
        file:writeFloat32(self.albedo.w);
        file:writeFloat32(self.smoothness);
        file:writeFloat32(self.metalMask);
        file:writeFloat32(self.parallaxStrength);
        if self.parallaxEdgeDiscard {file:writeUInt8(1);}
        else {file:writeUInt8(0);};
        file:writeUInt8(self.pomMinLayers);
        file:writeUInt8(self.pomMaxLayers);
        file:writeFloat32(self.minTessLevel);
        file:writeFloat32(self.maxTessLevel);
        file:writeFloat32(self.tessMinDistance);
        file:writeFloat32(self.tessMaxDistance);
        file:writeFloat32(self.displacementStrength);
        file:writeFloat32(self.displacementMidlevel);
        self.writeTexture(file, self.albedoMap);
        self.writeTexture(file, self.materialMap);
        self.writeTexture(file, self.normalMap);
        self.writeTexture(file, self.parallaxHeightMap);
        self.writeTexture(file, self.pomHeightMap);
        self.writeTexture(file, self.displacementMap);
    };
    
    writeTexture = function(file, tex) {
        if isNil(tex) {
            file:writeUInt32LE(0);
        } else {
            file:writeUInt32LE(tex:getFilename().length);
            file:writeStr(tex:getFilename());
        };
    };
    
    readTexture = function(file) {
        resMgr = getResMgr();
        
        length = file:readUInt32LE();
        
        if length == 0 {
            return nil;
        } else {
            return resMgr:loadTexture(file:readStr(length));
        };
    };
    
    copyFrom = function(self, src) {
        self.smoothness = src.smoothness;
        self.metalMask = src.metalMask;
        self.parallaxStrength = src.parallaxStrength;
        self.parallaxEdgeDiscard = src.parallaxEdgeDiscard;
        self.albedo = src.albedo;
        self.pomMinLayers = src.pomMinLayers;
        self.pomMaxLayers = src.pomMaxLayers;
        self.tessMinDistance = src.tessMinDistance;
        self.tessMaxDistance = src.tessMaxDistance;
        self.displacementStrength = src.displacementStrength;
        self.displacementMidlevel = src.displacementMidlevel;
        self.shadowTesselation = src.shadowTesselation;
        self.shadowMinTessLevel = src.shadowMinTessLevel;
        self.shadowMaxTessLevel = src.shadowMaxTessLevel;
        self:setMaterialMap(src.materialMap);
        self:setAlbedoMap(src.albedoMap);
        self:setNormalMap(src.normalMap);
        self:setParallaxHeightMap(src.parallaxHeightMap);
        self:setPOMHeightMap(src.pomHeightMap);
    };
    
    setupRender = function(self, mesh, animState, camera) {
        gfxApi = getGfxApi();
        
        useTesselation = not isNil(self.displacementMap) and
                         (mesh.primitive == GfxPrimitive.GfxTriangles);
        
        animated = not isNil(animState);
        
        if animated {shaders = self.shadersAnim;}
        else {shaders = self.shaders;};
        
        vertex = shaders:getCompiled(GfxShaderType.Vertex);
        tessControl = shaders:getCompiled(GfxShaderType.TessControl);
        tessEval = shaders:getCompiled(GfxShaderType.TessEval);
        fragment = shaders:getCompiled(GfxShaderType.Fragment);
        
        gfxApi:begin(shaders);
        gfxApi:setMesh(mesh);
        
        proj = camera:getProjectionMatrix();
        view = camera:getViewMatrix();
        
        gfxApi:uniform(vertex, "cameraPosition", camera:getPosition());
        
        if useTesselation {
            gfxApi:uniform(vertex, "projectionViewMatrix", Matrix4x4());
            gfxApi:uniform(tessControl, "minTessLevel", self.minTessLevel);
            gfxApi:uniform(tessControl, "maxTessLevel", self.maxTessLevel);
            gfxApi:uniform(tessControl, "tessMinDistance", self.tessMinDistance);
            gfxApi:uniform(tessControl, "tessMaxDistance", self.tessMaxDistance);
            gfxApi:uniform(tessControl, "cameraPosition", camera:getPosition());
            
            gfxApi:addTextureBinding2(tessEval, "heightMap", self.displacementMap);
            gfxApi:uniform(tessEval, "displacementMidlevel", self.displacementMidlevel);
            gfxApi:uniform(tessEval, "projectionViewMatrix", proj * view);
            gfxApi:uniform(tessEval, "strength", self.displacementStrength);
        } else {
            gfxApi:uniform(vertex, "projectionViewMatrix", proj * view);
        };
        
        gfxApi:uniform(fragment, "smoothness", self.smoothness);
        gfxApi:uniform(fragment, "metalMask", self.metalMask);
        gfxApi:uniform(fragment, "albedo", self.albedo);
        
        if not isNil(self.materialMap) {
            gfxApi:addTextureBinding2(fragment, "materialMap", self.materialMap);
        };
        
        if not isNil(self.albedoMap) {
            gfxApi:addTextureBinding2(fragment, "albedoMap", self.albedoMap);
        };
        
        if not isNil(self.normalMap) {
            gfxApi:addTextureBinding2(fragment, "normalMap", self.normalMap);
        };
        
        if not isNil(self.parallaxHeightMap) {
            gfxApi:addTextureBinding2(fragment, "heightMap", self.parallaxHeightMap);
            gfxApi:uniform(fragment, "heightScale", self.parallaxStrength);
            if self.parallaxEdgeDiscard {gfxApi:uniform(fragment, "parallaxEdgeDiscard", 1);}
            else {gfxApi:uniform(fragment, "parallaxEdgeDiscard", 0);};
        } elif not isNil(self.pomHeightMap) {
            gfxApi:addTextureBinding2(fragment, "heightMap", self.pomHeightMap);
            gfxApi:uniform(fragment, "heightScale", self.parallaxStrength);
            if self.parallaxEdgeDiscard {gfxApi:uniform(fragment, "parallaxEdgeDiscard", 1);}
            else {gfxApi:uniform(fragment, "parallaxEdgeDiscard", 0);};
            gfxApi:uniformU(fragment, "pomMinLayers", self.pomMinLayers);
            gfxApi:uniformU(fragment, "pomMaxLayers", self.pomMaxLayers);
        };
        
        if animated {
            gfxApi:addUBOBinding(vertex, "bonePositionData", animState:getMatrixBuffer());
            gfxApi:addUBOBinding(vertex, "boneNormalData", animState:getNormalMatrixBuffer());
        };
        
        gfxApi:setTessPatchSize(3);
    };
    
    setDisplacementMap = function(self, map) {
        resMgr = getResMgr();
        
        self.displacementMap = map;
        
        if not isNil(map) {
            tessControl = resMgr:loadShader("resources/shaders/object.tcs.bin");
            tessEval = resMgr:loadShader("resources/shaders/object.tes.bin");
            
            self.shaders:setShader(GfxShaderType.TessControl, tessControl);
            self.shaders:setShader(GfxShaderType.TessEval, tessEval);
            self.shadersAnim:setShader(GfxShaderType.TessControl, tessControl);
            self.shadersAnim:setShader(GfxShaderType.TessEval, tessEval);
        } else {
            "TODO
            enable this
            comments don't seem to work
            self.shaders:setShader(GfxShaderType.TessControl, nil);
            self.shaders:setShader(GfxShaderType.TessEval, nil);
            self.shadersAnim:setShader(GfxShaderType.TessControl, nil);
            self.shadersAnim:setShader(GfxShaderType.TessEval, nil);";
        };
    };
    
    setMaterialMap = function(self, map) {
        self.materialMap = map;
        
        if isNil(map) {
            self.shaders:removeDefine(GfxShaderType.Fragment, "MATERIAL_MAP");
            self.shadersAnim:removeDefine(GfxShaderType.Fragment, "MATERIAL_MAP");
        } else {
            self.shaders:setDefine(GfxShaderType.Fragment, "MATERIAL_MAP", "1");
            self.shadersAnim:setDefine(GfxShaderType.Fragment, "MATERIAL_MAP", "1");
        };
    };
    
    setAlbedoMap = function(self, map) {
        self.albedoMap = map;
        
        if isNil(map) {
            self.shaders:removeDefine(GfxShaderType.Fragment, "ALBEDO_MAP");
            self.shadersAnim:removeDefine(GfxShaderType.Fragment, "ALBEDO_MAP");
        } else {
            self.shaders:setDefine(GfxShaderType.Fragment, "ALBEDO_MAP", "1");
            self.shadersAnim:setDefine(GfxShaderType.Fragment, "ALBEDO_MAP", "1");
        };
    };
    
    setNormalMap = function(self, map) {
        self.normalMap = map;
        
        if isNil(map) {
            self.shaders:removeDefine(GfxShaderType.Fragment, "NORMAL_MAP");
            self.shadersAnim:removeDefine(GfxShaderType.Fragment, "NORMAL_MAP");
        } else {
            self.shaders:setDefine(GfxShaderType.Fragment, "NORMAL_MAP", "1");
            self.shadersAnim:setDefine(GfxShaderType.Fragment, "NORMAL_MAP", "1");
        };
    };
    
    setParallaxHeightMap = function(self, map) {
        self.parallaxHeightMap = map;
        
        if isNil(map) {
            self.shaders:removeDefine(GfxShaderType.Fragment, "PARALLAX_MAPPING");
            self.shadersAnim:removeDefine(GfxShaderType.Fragment, "PARALLAX_MAPPING");
        } else {
            self.shaders:setDefine(GfxShaderType.Fragment, "PARALLAX_MAPPING", "1");
            self.shadersAnim:setDefine(GfxShaderType.Fragment, "PARALLAX_MAPPING", "1");
        };
    };
    
    setPOMHeightMap = function(self, map) {
        self.pomHeightMap = map;
        
        if isNil(map) {
            self.shaders:removeDefine(GfxShaderType.Fragment, "POM");
            self.shadersAnim:removeDefine(GfxShaderType.Fragment, "POM");
        } else {
            self.shaders:setDefine(GfxShaderType.Fragment, "POM", "1");
            self.shadersAnim:setDefine(GfxShaderType.Fragment, "POM", "1");
        };
    };
};


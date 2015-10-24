return class {
    __init__ = function(self) {
        resMgr = getResMgr();
        
        vertex = resMgr:loadShader("resources/shaders/shadowmap.vs.bin");
        geometry = resMgr:loadShader("resources/shaders/pointShadowmap.gs.bin");
        fragment = resMgr:loadShader("resources/shaders/shadowmap.fs.bin");
        pointFragment = resMgr:loadShader("resources/shaders/pointShadowmap.fs.bin");
        
        self.vertex = vertex:getCompiled(StrStrMap());
        
        defines = StrStrMap();
        defines:set("SKELETAL_ANIMATION", "1");
        self.vertexAnim = vertex:getCompiled(defines);
        
        self.geometry = geometry:getCompiled(StrStrMap());
        self.fragment = fragment:getCompiled(StrStrMap());
        self.pointFragment = pointFragment:getCompiled(StrStrMap());
    };
    __del__ = function(self) {};
    
    load = function(self, file) {};
    save = function(self, file) {};
    
    copyFrom = function(self, src) {};
    
    setupShadowRender = function(self, mesh, animState, light, pass) {
        gfxApi = getGfxApi();
        
        animated = not isNil(animState);
        
        if animated {vertex = self.vertexAnim;}
        else {vertex = self.vertex;};
        
        geometry = nil;
        fragment = self.fragment;
        
        if light.type == GfxLightType.Point {
            fragment = self.pointFragment;
            if light.point.singlePassShadowmap {geometry = self.geometry;};
        };
        
        if isNil(geometry) {gfxApi:begin(vertex, fragment, mesh);}
        else {gfxApi:begin(vertex, geometry, fragment, mesh);};
        
        proj = light:getProjectionMatrix();
        view = light:getViewMatrix();
        
        if light.type == GfxLightType.Point {
            pos = light.point.position;
            
            if light.point.singlePassShadowmap {
                matrix0 = lookAtDirMat(pos, Float3(1.0, 0.0, 0.0), Float3(0.0, -1.0, 0.0));
                matrix1 = lookAtDirMat(pos, Float3(-1.0, 0.0, 0.0), Float3(0.0, -1.0, 0.0));
                matrix2 = lookAtDirMat(pos, Float3(0.0, 1.0, 0.0), Float3(0.0, 0.0, 1.0));
                matrix3 = lookAtDirMat(pos, Float3(0.0, -1.0, 0.0), Float3(0.0, 0.0, -1.0));
                matrix4 = lookAtDirMat(pos, Float3(0.0, 0.0, 1.0), Float3(0.0, -1.0, 0.0));
                matrix5 = lookAtDirMat(pos, Float3(0.0, 0.0, -1.0), Float3(0.0, -1.0, 0.0));
                
                gfxApi:uniform(geometry, "matrix0", proj * matrix0);
                gfxApi:uniform(geometry, "matrix1", proj * matrix1);
                gfxApi:uniform(geometry, "matrix2", proj * matrix2);
                gfxApi:uniform(geometry, "matrix3", proj * matrix3);
                gfxApi:uniform(geometry, "matrix4", proj * matrix4);
                gfxApi:uniform(geometry, "matrix5", proj * matrix5);
                
                gfxApi:uniform(vertex, "projectionMatrix", Matrix4x4());
                gfxApi:uniform(vertex, "viewMatrix", Matrix4x4());
            } else {
                if pass == 0 {mat = matrix0;}
                elif pass == 1 {mat = matrix1;}
                elif pass == 2 {mat = matrix2;}
                elif pass == 3 {mat = matrix3;}
                elif pass == 4 {mat = matrix4;}
                elif pass == 5 {mat = matrix5;};
                
                gfxApi:uniform(vertex, "projectionMatrix", proj);
                gfxApi:uniform(vertex, "viewMatrix", mat);
            };
            
            gfxApi:uniform(fragment, "lightPos", pos);
            gfxApi:uniform(fragment, "lightFar", light:getPointLightInfluence());
        } elif light.type == GfxLightType.Directional {
            gfxApi:uniform(vertex, "projectionMatrix", light:getCascadeProjectionMatrix(pass));
            gfxApi:uniform(vertex, "viewMatrix", light:getCascadeViewMatrix(pass));
        } else {
            gfxApi:uniform(vertex, "projectionMatrix", proj);
            gfxApi:uniform(vertex, "viewMatrix", view);
        };
        
        gfxApi:uniform(fragment, "biasScale", light.shadowAutoBiasScale);
        
        if animated {
            gfxApi:addUBOBinding(vertex, "bonePositionData", animState:getMatrixBuffer());
        };
    };
    
    isForward = function(self) {
        return false;
    };
};


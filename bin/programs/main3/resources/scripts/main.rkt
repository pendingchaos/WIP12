return class {
    __init__ = function(self) {
        resMgr = getResMgr();
        gfxApi = getGfxApi();
        
        self.scene = resMgr:loadScene("resources/scenes/main.bin");
        self.font = resMgr:loadFont("/usr/share/fonts/gnu-free/FreeSans.ttf");
        
        self.showExtraTimings = false;
        self.timingsUpdateCountdown = 0.0;
        self.freezeTimings = false;
        self.timings = "";
        self.extraTimings = "";
        self.textGPUTiming = 0.0;
        self.textCPUTiming = 0.0;
        self.textTimer = gfxApi:createTimer();
        
        self.chunk = MCChunk(16, 16, 16, 4, 0.5);
        self.chunk:setMaterial(1, resMgr:loadMaterial("resources/materials/grass.bin"));
        self.chunk:setMaterial(2, resMgr:loadMaterial("resources/materials/dirt.bin"));
        self.chunk:setMaterial(3, resMgr:loadMaterial("resources/materials/stone.bin"));
        self.chunk:setMaterial(4, resMgr:loadMaterial("resources/materials/bricks.bin"));
        
        self.numCubes = self.chunk:generateSphere(2, 4);
        
        self.chunk:updateMeshes();
        self.chunk:updateRigidBodies(self.scene:getPhysicsWorld());
    };
    
    __del__ = function(self) {};
    
    handleInput = function(self) {
        platform = getPlatform();
        app = getApp();
        
        while platform:eventsLeft() {
            event = platform:popEvent();
            
            if event.type == EventType.Quit {
                app.running = false;
            } elif event.type == EventType.KeyDown {
                key = event:getKey();
                
                if key == Key.F1 {
                    fullscreen = platform:getFullscreen();
                    platform:setFullscreen(not fullscreen);
                } elif key == Key.F2 {
                    self.showExtraTimings = not self.showExtraTimings;
                } elif key == Key.F3 {
                    self.freezeTimings = not self.freezeTimings;
                } elif key == Key.F4 {
                    renderer = self.scene:getRenderer();
                    renderer.debugDraw = not renderer.debugDraw;
                } elif key == Key.Escape {
                    platform:setFullscreen(false);
                };
            };
        };
        
        self.scene:handleInput();
    };
    
    update = function(self) {
        self.scene:update();
    };
    
    fixedUpdate = function(self, timestep) {
        self.scene:fixedUpdate(timestep)
    };
    
    preRender = function(self) {};
    
    postRender = function(self) {
        platform = getPlatform();
        width = platform:getWindowWidth();
        height = platform:getWindowHeight();
        renderer = self.scene:getRenderer();
        gfxApi = getGfxApi();
        app = getApp();
        frametime = platform:getFrametime();
        
        gfxApi:setViewport(0, 0, width, height);
        
        self.timingsUpdateCountdown = self.timingsUpdateCountdown - frametime;
        
        if renderer.debugDraw {
            self.scene:getPhysicsWorld():debugDraw();
        };
        
        renderer:resize(UInt2(width, height));
        renderer:render();
        self.chunk:render(renderer, Matrix4x4());
        
        gfxStats = renderer:getStats();
        
        if (self.timingsUpdateCountdown < 0.0) and (not self.freezeTimings) {
            self.timingsUpdateCountdown = 0.1;
            
            cubeNames = List();
            cubeNames:append("Grass");
            cubeNames:append("Dirt");
            cubeNames:append("Stone");
            cubeNames:append("Bricks");
            
            format = "FPS: %v
Frametime: %v ms
GPU Frametime: %v ms
CPU Frametime: %v ms
Draw calls: %v
Cube count: %v
Cube: %v
";
            
            gpuFrametime = platform:getGPUFrametime();
            cpuFrametime = platform:getCPUFrametime();
            
            player = self.scene:findEntity("Player");
            player = player:findScriptInstanceObj("resources/scripts/player.rkt");
            
            self.timings = format:format(1.0 / frametime,
                                         frametime * 1000.0,
                                         gpuFrametime * 1000.0,
                                         cpuFrametime * 1000.0,
                                         gfxStats.numDrawCalls,
                                         self.numCubes,
                                         cubeNames:get(player.cube-1));
            
            cpuStats = app:getStats();
            
            textTimer = self.textTimer;
            if textTimer:resultAvailable() {
                self.textGPUTiming = (0.0+textTimer.getResult(textTimer)) / textTimer.getResultResolution(textTimer);
            };
            
            sum = gfxStats.gBufferTiming +
                  gfxStats.ssaoTiming +
                  gfxStats.ssaoBlurXTiming +
                  gfxStats.ssaoBlurYTiming +
                  gfxStats.deferredShadingTiming +
                  gfxStats.forwardTiming +
                  gfxStats.gammaCorrectionTiming +
                  gfxStats.fxaaTiming +
                  gfxStats.colorModifierTiming +
                  gfxStats.bloomTiming +
                  gfxStats.shadowmapTiming +
                  gfxStats.overlayTiming +
                  gfxStats.debugDrawTiming +
                  self.textGPUTiming;
            
            postRenderSum = gfxStats.shadowmapCPUTiming +
                            gfxStats.gbufferCPUTiming +
                            gfxStats.forwardCPUTiming +
                            gfxStats.overlayCPUTiming +
                            gfxStats.batchingCPUTiming +
                            gfxStats.animationCPUTiming +
                            gfxStats.deferredShadingCPUTiming +
                            gfxStats.updateStatsCPUTiming +
                            gfxStats.miscPostEffectsCPUTiming +
                            self.textCPUTiming;
            
            format = "GPU Timing:
    GBuffer: %v ms (%v%%)
    SSAO: %v ms (%v%%)
    SSAO blur X: %v ms (%v%%)
    SSAO blur Y: %v ms (%v%%)
    Deferred shading: %v ms (%v%%)
    Forward render: %v ms (%v%%)
    Gamma correction: %v ms (%v%%)
    FXAA: %v ms (%v%%)
    Color modifiers: %v ms (%v%%)
    Bloom: %v ms (%v%%)
    Shadow map: %v ms (%v%%)
    Debug draw: %v ms (%v%%)
    Text: %v ms (%v%%)
    Overlays: %v ms (%v%%)
    Other: %v ms (%v%%)
CPU Timings:
    Input: %v ms (%v%%)
    Update: %v ms (%v%%)
    Fixed Update: %v ms (%v%%)
    Pre Render: %v ms (%v%%)
    Post Render: %v ms (%v%%)
        Shadowmap: %v ms (%v%%)
        G Buffer: %v ms (%v%%)
        Forward: %v ms (%v%%)
        Overlay: %v ms (%v%%)
        Batching: %v ms (%v%%)
        Animation: %v ms (%v%%)
        Deferred shading: %v ms (%v%%)
        Update stats: %v ms (%v%%)
        Misc post effects: %v ms (%v%%)
        Text: %v ms (%v%%)
        Other: %v ms(%v%%)
    Audio: %v ms (%v%%)";
            
            self.extraTimings = format:format(gfxStats.gBufferTiming * 1000.0,
                                              gfxStats.gBufferTiming / gpuFrametime * 100.0,
                                              gfxStats.ssaoTiming * 1000.0,
                                              gfxStats.ssaoTiming / gpuFrametime * 100.0,
                                              gfxStats.ssaoBlurXTiming * 1000.0,
                                              gfxStats.ssaoBlurXTiming / gpuFrametime * 100.0,
                                              gfxStats.ssaoBlurYTiming * 1000.0,
                                              gfxStats.ssaoBlurYTiming / gpuFrametime * 100.0,
                                              gfxStats.deferredShadingTiming * 1000.0,
                                              gfxStats.deferredShadingTiming / gpuFrametime * 100.0,
                                              gfxStats.forwardTiming * 1000.0,
                                              gfxStats.forwardTiming / gpuFrametime * 100.0,
                                              gfxStats.gammaCorrectionTiming * 1000.0,
                                              gfxStats.gammaCorrectionTiming / gpuFrametime * 100.0,
                                              gfxStats.fxaaTiming * 1000.0,
                                              gfxStats.fxaaTiming / gpuFrametime * 100.0,
                                              gfxStats.colorModifierTiming * 1000.0,
                                              gfxStats.colorModifierTiming / gpuFrametime * 100.0,
                                              gfxStats.bloomTiming * 1000.0,
                                              gfxStats.bloomTiming / gpuFrametime * 100.0,
                                              gfxStats.shadowmapTiming * 1000.0,
                                              gfxStats.shadowmapTiming / gpuFrametime * 100.0,
                                              gfxStats.debugDrawTiming * 1000.0,
                                              gfxStats.debugDrawTiming / gpuFrametime * 100.0,
                                              self.textGPUTiming * 1000.0,
                                              self.textGPUTiming / gpuFrametime * 100.0,
                                              gfxStats.overlayTiming * 1000.0,
                                              gfxStats.overlayTiming / gpuFrametime * 100.0,
                                              (gpuFrametime - sum) * 1000.0,
                                              (gpuFrametime - sum) / gpuFrametime * 100.0,
                                              cpuStats.handleInput * 1000.0,
                                              cpuStats.handleInput / cpuFrametime * 100.0,
                                              cpuStats.update * 1000.0,
                                              cpuStats.update / cpuFrametime * 100.0,
                                              cpuStats.fixedUpdate * 1000.0,
                                              cpuStats.fixedUpdate / cpuFrametime * 100.0,
                                              cpuStats.preRender * 1000.0,
                                              cpuStats.preRender / cpuFrametime * 100.0,
                                              cpuStats.postRender * 1000.0,
                                              cpuStats.postRender / cpuFrametime * 100.0,
                                              gfxStats.shadowmapCPUTiming * 1000.0,
                                              gfxStats.shadowmapCPUTiming / cpuFrametime * 100.0,
                                              gfxStats.gbufferCPUTiming * 1000.0,
                                              gfxStats.gbufferCPUTiming / cpuFrametime * 100.0,
                                              gfxStats.forwardCPUTiming * 1000.0,
                                              gfxStats.forwardCPUTiming / cpuFrametime * 100.0,
                                              gfxStats.overlayCPUTiming * 1000.0,
                                              gfxStats.overlayCPUTiming / cpuFrametime * 100.0,
                                              gfxStats.batchingCPUTiming * 1000.0,
                                              gfxStats.batchingCPUTiming / cpuFrametime * 100.0,
                                              gfxStats.animationCPUTiming * 1000.0,
                                              gfxStats.animationCPUTiming / cpuFrametime * 100.0,
                                              gfxStats.deferredShadingCPUTiming * 1000.0,
                                              gfxStats.deferredShadingCPUTiming / cpuFrametime * 100.0,
                                              gfxStats.updateStatsCPUTiming * 1000.0,
                                              gfxStats.updateStatsCPUTiming / cpuFrametime * 100.0,
                                              gfxStats.miscPostEffectsCPUTiming * 1000.0,
                                              gfxStats.miscPostEffectsCPUTiming / cpuFrametime * 100.0,
                                              self.textCPUTiming * 1000.0,
                                              self.textCPUTiming / cpuFrametime * 100.0,
                                              (cpuStats.postRender - postRenderSum) * 1000.0,
                                              (cpuStats.postRender - postRenderSum) / cpuStats.postRender * 100.0,
                                              cpuStats.audio * 1000.0,
                                              cpuStats.audio / cpuFrametime * 100.0);
        };
        
        displayedText = self.timings;
        if self.showExtraTimings {
            displayedText = displayedText + self.extraTimings;
        };
        
        self.textTimer:swap();
        self.textTimer:begin();
        start = platform:getTime();
        
        y = height - 40.0;
        y = y / height;
        
        self.font:render(40, Float2(-1.0, y), displayedText, Float3(1.0));
        
        self.textCPUTiming = (platform:getTime() - start + 0.0) / platform:getTimerFrequency();
        self.textTimer:end();
    };
};


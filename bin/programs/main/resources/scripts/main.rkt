return class {
    __init__ = function(self) {
        resMgr = getResMgr();
        gfxApi = getGfxApi();
        
        self.scene = resMgr.loadScene(resMgr, "resources/scenes/scene.bin");
        self.font = resMgr.loadFont(resMgr,
                                    "/usr/share/fonts/gnu-free/FreeSans.ttf");
        
        self.showExtraTimings = false;
        self.timingsUpdateCountdown = 0.0;
        self.freezeTimings = false;
        self.timings = "";
        self.extraTimings = "";
        self.textGPUTiming = 0.0;
        self.textCPUTiming = 0.0;
        self.textTimer = gfxApi.createTimer(gfxApi);
    };
    
    __del__ = function(self) {};
    
    handleInput = function(self) {
        platform = getPlatform();
        app = getApp();
        
        while platform.eventsLeft(platform) {
            event = platform.popEvent(platform);
            
            if event.type == EventType.Quit {
                app.running = false;
            } elif event.type == EventType.KeyDown {
                key = event.getKey(event);
                
                if key == Key.F1 {
                    fullscreen = platform.getFullscreen(platform);
                    platform.setFullscreen(platform, not fullscreen);
                } elif key == Key.F2 {
                    self.showExtraTimings = not self.showExtraTimings;
                } elif key == Key.F3 {
                    self.freezeTimings = not self.freezeTimings;
                } elif key == Key.F4 {
                    renderer = self.scene.getRenderer(self.scene);
                    renderer.debugDraw = not renderer.debugDraw;
                } elif key == Key.Escape {
                    platform.setFullscreen(platform, false);
                };
            };
        };
        
        self.scene.handleInput(self.scene);
    };
    
    update = function(self) {
        self.scene.update(self.scene);
    };
    
    fixedUpdate = function(self, timestep) {
        self.scene.fixedUpdate(self.scene, timestep)
    };
    
    preRender = function(self) {};
    
    postRender = function(self) {
        platform = getPlatform();
        width = platform.getWindowWidth(platform);
        height = platform.getWindowHeight(platform);
        renderer = self.scene.getRenderer(self.scene);
        gfxApi = getGfxApi();
        app = getApp();
        frametime = platform.getFrametime(platform);
        
        gfxApi.setViewport(gfxApi, 0, 0, width, height);
        
        self.timingsUpdateCountdown = self.timingsUpdateCountdown - frametime;
        
        if renderer.debugDraw {
            world = self.scene.getPhysicsWorld(self.scene);
            world.debugDraw(world);
        };
        
        renderer.resize(renderer, UInt2(width, height));
        renderer.render(renderer);
        
        gfxStats = renderer.getStats(renderer);
        
        if (self.timingsUpdateCountdown < 0.0) and (not self.freezeTimings) {
            self.timingsUpdateCountdown = 0.1;
            
            format = "FPS: %v
Frametime: %v ms
GPU Frametime: %v ms
CPU Frametime: %v ms
Draw calls: %v
";
            
            gpuFrametime = platform.getGPUFrametime(platform);
            cpuFrametime = platform.getCPUFrametime(platform);
            
            self.timings = format.format(format,
                                         1.0 / frametime,
                                         frametime * 1000.0,
                                         gpuFrametime * 1000.0,
                                         cpuFrametime * 1000.0,
                                         gfxStats.numDrawCalls);
            
            cpuStats = app.getStats(app);
            
            textTimer = self.textTimer;
            if textTimer.resultAvailable(textTimer) {
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
        Text: %v ms (%v%%)
    Audio: %v ms (%v%%)";
            
            self.extraTimings = format.format(format,
                                              gfxStats.gBufferTiming * 1000.0,
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
                                              gfxStats.batchingTiming * 1000.0,
                                              gfxStats.batchingTiming / cpuFrametime * 100.0,
                                              self.textCPUTiming * 1000.0,
                                              self.textCPUTiming / cpuFrametime * 100.0,
                                              cpuStats.audio * 1000.0,
                                              cpuStats.audio / cpuFrametime * 100.0);
        };
        
        displayedText = self.timings.copy(self.timings);
        
        if self.showExtraTimings {
            displayedText.append(displayedText, self.extraTimings);
        };
        
        self.textTimer.swap(self.textTimer);
        self.textTimer.begin(self.textTimer);
        start = platform.getTime(platform);
        
        y = height - 40.0;
        y = y / height;
        
        #TODO: nil -> NULL
        #self.font.render(self.font, 40, Float2(-1.0, y), displayedText, nil, Float3(1.0));
        
        self.textCPUTiming = (platform.getTime(platform) - start + 0.0) / platform.getTimerFrequency(platform);
        self.textTimer.end(self.textTimer);
    };
};


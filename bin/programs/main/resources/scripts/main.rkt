return class {
    __init__ = function(self) {
        resMgr = getResMgr();
        self.scene = resMgr.loadScene(resMgr, "resources/scenes/scene.bin");
        self.font = resMgr.loadFont(resMgr,
                                    "/usr/share/fonts/gnu-free/FreeSans.ttf");
        
        self.showExtraTimings = false;
        self.timingsUpdateCountdown = 0.0;
        self.freezeTimings = false;
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
        
        self.timingsUpdateCountdown = self.timingsUpdateCountdown - platform.getFrametime(platform);
        
        if (renderer.debugDraw) {
            world = self.scene.getPhysicsWorld(self.scene);
            world.debugDraw(world);
        };
        
        renderer.resize(renderer, UInt2(width, height));
        renderer.render(renderer);
    };
};


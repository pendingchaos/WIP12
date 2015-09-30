return class {
    __init__ = function(self) {
        resMgr = getResMgr();
        self.scene = resMgr.loadScene(resMgr, "resources/scenes/scene.bin");
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
                if event.getKey(event) == Key.F1 {
                    fullscreen = platform.getFullscreen(platform);
                    platform.setFullscreen(platform, not fullscreen);
                } elif event.getKey(event) == Key.Escape {
                    platform.setFullscreen(platform, false);
                }
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
        renderer.resize(renderer, UInt2(width, height));
        renderer.render(renderer);
    };
};


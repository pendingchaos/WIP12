return class {
    __init__ = function(self, entity) {
        self.entity = entity;
        self.scene = entity:getScene();
    };
    
    __del__ = function(self) {};
    
    handleInput = function(self) {};
    
    update = function(self) {};
    
    fixedUpdate = function(self, timestep) {
        if self.entity:hasRenderComponent() {
            anim = self.entity:getRenderComponent():getAnimationState();
            
            if not isNil(anim)
            {
                anim.timeOffset = anim.timeOffset + timestep;
            };
        };
    };
    
    preRender = function(self) {};
    postRender = function(self) {};
};


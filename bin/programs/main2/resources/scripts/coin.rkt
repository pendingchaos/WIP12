return class {
    __init__ = function(self, entity)
    {
        self.entity = entity;
        self.shrinking = false;
    };
    
    __del__ = function(self) {};
    
    handleInput = function(self) {};
    update = function(self) {};
    
    fixedUpdate = function(self, timestep)
    {
        if self.shrinking {
            entity = self.entity;
            transform = entity.transform;
            transform.scale = transform.scale * 0.9;
            entity.transform = transform;
            
            # TODO: Destroy
            if (transform.scale.x < 0.001) or
               (transform.scale.y < 0.001) or
               (transform.scale.z < 0.001) {
            
            };
        };
    };
    
    preRender = function(self) {};
    postRender = function(self) {};
    
    onCollect = function(self) {
        self.shrinking = true;
    };
};


return class {
    __init__ = function(self, entity) {
        self.entity = entity;
        self.shrinking = false;
        self.entity:getRigidBody():setGravity(Float3(0.0));
    };
    
    __del__ = function(self) {};
    
    handleInput = function(self) {};
    update = function(self) {};
    
    fixedUpdate = function(self, timestep) {
        if self.shrinking {
            entity = self.entity;
            transform = entity.transform;
            transform.scale = transform.scale * 0.9;
            
            # TODO: Destroy
            if (transform.scale.x < 0.001) or
               (transform.scale.y < 0.001) or
               (transform.scale.z < 0.001) {
                self.shrinking = false;
                tf = Transform();
                tf.position = Float3(0.0, -10000.0, 0.0);
                self.entity:getRigidBody():setTransform(tf:createMatrix());
                self.entity:removeRenderComponent();
            };
            
            entity.transform = transform;
        };
    };
    
    preRender = function(self) {};
    postRender = function(self) {};
    
    onCollect = function(self) {
        self.shrinking = true;
    };
};


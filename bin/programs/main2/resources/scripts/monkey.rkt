return class {
    __init__ = function(self, entity)
    {
        self.entity = entity;
        self.scene = entity:getScene();
        self.attacked = false;
        self.speed = 5.0;
        
        physicsWorld = self.scene:getPhysicsWorld();
        
        shape = PhysicsShape();
        shape:setSphere(10.0);
        self.playerGhost = physicsWorld:createGhostObject(shape, 0xFFFF );
    };
    
    __del__ = function(self)
    {
        self.scene:getPhysicsWorld():destroyGhostObject(self.playerGhost);
    };
    
    handleInput = function(self) {};
    update = function(self) {};
    
    fixedUpdate = function(self, timestep)
    {
        body = self.entity:getRigidBody();
        
        self.playerGhost:setTransform(self.entity.transform);
        
        if self.attacked {
            entity = self.entity;
            transform = entity.transform;
            transform.scale = transform.scale * 0.9;
            
            orientation = transform.orientation;
            orientation:setAngle((orientation:getAngle() + 0.39269875) % (PI*2.0));
            transform.orientation = orientation;
            
            # TODO: Destroy
            if (transform.scale.x < 0.001) or
               (transform.scale.y < 0.001) or
               (transform.scale.z < 0.001) {
                self.attacked = false;
                body:setGravity(Float3(0.0, 10000.0, 0.0));
                tf = Transform();
                tf.position = Float3(0.0, 0.0, 0.0);
                self.entity:getRigidBody():setTransform(tf:createMatrix());
                self.entity:removeRenderComponent();
            };
            
            entity.transform = transform;
        } else {
            rigidBodies = self.playerGhost:getRigidBodyCollisions();
            i = 0;
            while i < rigidBodies:getCount() {
                player = rigidBodies:get(i):getEntity();
                if player.name == "Player" {
                    entity = self.entity;
                    
                    dir = player.transform.position - entity.transform.position;
                    dir.y = 0.0;
                    dir = dir:normalize();
                    
                    body:setLinearVelocity(dir * self.speed);
                };
                
                i = i + 1;
            };
        };
    };
    
    preRender = function(self) {};
    postRender = function(self) {};
};


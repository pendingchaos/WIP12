return class {
    __init__ = function(self, entity) {
        self.entity = entity;
        self.scene = entity:getScene();
        
        self.speed = 10.0;
        self.zoom = 1.0;
        self.maxVel = 12.0;
        self.zoom = 1.0;
        self.onFloor = false;
        
        body = entity:getRigidBody();
        body:setAngularFactor(Float3(0.0));
        
        physicsWorld = self.scene:getPhysicsWorld();
        
        shape = PhysicsShape();
        shape:setCylinder(Axis.Y, 0.1, 0.8);
        self.feetGhost = physicsWorld:createGhostObject(shape, 0xFFFF ); #TODO: A space is required.
    };
    
    __del__ = function(self)
    {
        self.scene:getPhysicsWorld():destroyGhostObject(self.feetGhost);
    };
    
    handleInput = function(self) {};
    
    update = function(self) {};
    
    fixedUpdate = function(self, timestep) {
        feetTransform = self.entity.transform;
        
        pos = feetTransform.position;
        pos = Float3(pos.x, pos.y - 1.33, pos.z);
        feetTransform.position = pos;
        
        self.feetGhost:setTransform(feetTransform);
        
        rigidBodies = self.feetGhost:getRigidBodyCollisions();
        self.onFloor = rigidBodies:getCount() != 0;
        
        platform = getPlatform();
        body = self.entity:getRigidBody();
        renderer = self.scene:getRenderer();
        
        cam = renderer.camera;
        
        dir = Float3(-1.0, -1.0, -1.0);
        
        cam:setDirection(dir);
        
        right = Float3(1.0, 0.0, -1.0);
        
        cam:setUp(right:cross(dir));
        
        resSpeed = self.speed;
        
        if platform:isKeyPressed(Key.Space) {
            resSpeed = resSpeed * 2.0;
        };
        
        vel = Float3();
        
        if platform:isKeyPressed(Key.A) {
            vel = vel - right*timestep*resSpeed;
        };
        
        if platform:isKeyPressed(Key.D) {
            vel = vel + right*timestep*resSpeed;
        };
        
        if platform:isKeyPressed(Key.W) {
            vel = vel + dir*timestep*resSpeed;
        };
        
        if platform:isKeyPressed(Key.S) {
            vel = vel - dir*timestep*resSpeed;
        };
        
        vel.y = 0.0;
        
        oldVel = body:getLinearVelocity();
        newVel = oldVel + vel;
        
        if newVel.x > self.maxVel {
            vel.x = vel.x - (newVel.x - self.maxVel);
        } elif newVel.x < -self.maxVel {
            vel.x = vel.x + (abs(newVel.x) - self.maxVel);
        };
        
        if newVel.z > self.maxVel {
            vel.z = vel.z - (newVel.z - self.maxVel);
        } elif newVel.z < -self.maxVel {
            vel.z = vel.z + (abs(newVel.z) - self.maxVel);
        };
        
        body:setLinearVelocity(oldVel + vel);
        
        if platform:isKeyPressed(Key.Space) and self.onFloor {
            vel = body:getLinearVelocity();
            vel.y = 10.0;
            body:setLinearVelocity(vel);
        };
        
        if platform:getMouseWheel().y > 0.0 {
            self.zoom = self.zoom - timestep;
        } elif platform:getMouseWheel().y < 0.0 {
            self.zoom = self.zoom + timestep;
        };
        
        self.zoom = max(min(self.zoom, 1.7), 0.3);
        
        cam:setFieldOfView(self.zoom * 50.0);
        
        cam:setPosition(self.entity.transform.position + Float3(5.0, 5.0, 5.0));
        
        renderer.camera = cam;
    };
    
    preRender = function(self) {};
    postRender = function(self) {};
};


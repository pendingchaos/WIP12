return class {
    __init__ = function(self, entity) {
        self.entity = entity;
        self.scene = entity:getScene();
        
        self.angle = Float2(PI, 0.0);
        self.speed = 10.0;
        self.rotateSpeed = 0.125;
        self.zoom = 1.0;
        self.maxVel = 12.0;
        self.maxAngVel = 0.5;
        self.angVel = Float2(0.0, 0.0);
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
    
    update = function(self)
    {
        feetTransform = self.entity.transform;
        
        pos = feetTransform.position;
        pos = Float3(pos.x, pos.y - 2.2, pos.z);
        feetTransform.position = pos;
        
        self.feetGhost:setTransform(feetTransform);
        
        rigidBodies = self.feetGhost:getRigidBodyCollisions();
        self.onFloor = rigidBodies:getCount() != 0;
    };
    
    fixedUpdate = function(self, timestep) {
        platform = getPlatform();
        body = self.entity:getRigidBody();
        renderer = self.scene:getRenderer();
        
        cam = renderer.camera;
        
        dir = Float3(cos(self.angle.y) * sin(self.angle.x),
                     sin(self.angle.y),
                     cos(self.angle.y) * cos(self.angle.x));
        
        cam:setDirection(dir);
        
        right = Float3(sin(self.angle.x - PI/2.0),
                       0.0,
                       cos(self.angle.x - PI/2.0));
        
        cam:setUp(right.cross(right, dir));
        
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
        
        if platform:isLeftMouseButtonPressed() {
            platform:setCursorVisible(false);
            
            w = platform:getWindowWidth();
            h = platform:getWindowHeight();
            pos = platform:getMousePosition();
            
            platform:setMousePosition(Int2(w/2, h/2)); #TODO: Adding an extra ) does not raise an error.
            
            rel = Float2(w+0.0, h+0.0) / 2.0 - Float2(pos.x+0.0, pos.y+0.0);
            
            if (rel.x > -1.0) and (rel.x < 1.0) {
                rel.x = 0.0;
            };
            
            if (rel.y > -1.0) and (rel.y < 1.0) {
                rel.y = 0.0;
            };
            
            angVel = self.angVel;
            angVel.x = angVel.x + self.rotateSpeed*timestep*rel.x;
            angVel.y = angVel.y + self.rotateSpeed*timestep*rel.y;
            self.angVel = angVel;
        } else {
            platform:setCursorVisible(true);
        };
        
        angVel = self.angVel;
        angVel.x = min(self.angVel.x, self.maxAngVel);
        angVel.y = min(self.angVel.y, self.maxAngVel);
        
        angVel.x = max(self.angVel.x, -self.maxAngVel);
        angVel.y = max(self.angVel.y, -self.maxAngVel);
        self.angVel = angVel;
        
        self.angle = self.angle + self.angVel;
        
        angle = self.angle;
        angle.y = max(angle.y, -PI/2.0);
        angle.y = min(angle.y, PI/2.0);
        self.angle = angle;
        
        if platform:getMouseWheel().y > 0.0 {
            self.zoom = self.zoom - timestep;
        } elif platform:getMouseWheel().y < 0.0 {
            self.zoom = self.zoom + timestep;
        };
        
        self.zoom = max(min(self.zoom, 1.7), 0.3);
        
        cam:setFieldOfView(self.zoom * 50.0);
        
        angVel = self.angVel;
        angVel = angVel * timestep * 0.1;
        
        if (angVel.x > -0.001) and (angVel.x < 0.001) {
            angVel.x = 0.0;
        };
        
        if (angVel.y > -0.001) and (angVel.y < 0.001) {
            angVel.y = 0.0;
        };
        self.angVel = angVel;
        
        cam:setPosition(self.entity.transform.position + Float3(0.0, 1.5, 0.0));
        
        renderer.camera = cam;
    };
    
    preRender = function(self) {};
    postRender = function(self) {};
};


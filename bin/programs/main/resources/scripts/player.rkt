return class {
    __init__ = function(self, entity) {
        self.entity = entity;
        self.scene = entity.getScene(entity);
        
        self.angle = Float2(PI, 0.0);
        self.speed = 10.0;
        self.rotateSpeed = 0.125;
        self.zoom = 1.0;
        self.maxVel = 12.0;
        self.maxAngVel = 0.5;
        self.angVel = Float2(0.0, 0.0);
        self.zoom = 1.0;
        self.onFloor = false;
        
        body = entity.getRigidBody(entity);
        body.setAngularFactor(body, Float3(0.0));
        
        physicsWorld = self.scene.getPhysicsWorld(self.scene);
        
        shape = PhysicsShapeRef();
        shape.setCylinder(shape, Axis.Y, 0.1, 0.8);
        self.feetGhost = physicsWorld.createGhostObject(physicsWorld, shape, 0xFFFF ); #TODO: A space is required.
    };
    
    __del__ = function(self)
    {
        physicsWorld = self.scene.getPhysicsWorld(self.scene);
        physicsWorld.destroyGhostObject(physicsWorld, self.feetGhost);
    };
    
    handleInput = function(self) {};
    
    update = function(self)
    {
        feetTransform = self.entity.transform;
        
        pos = feetTransform.position;
        pos = Float3(pos.x, pos.y - 2.2, pos.z);
        feetTransform.position = pos;
        
        self.feetGhost.setTransform(self.feetGhost, feetTransform);
        
        rigidBodies = self.feetGhost.getRigidBodyCollisions(self.feetGhost);
        self.onFloor = rigidBodies.getCount(rigidBodies) != 0;
    };
    
    fixedUpdate = function(self, timestep) {
        platform = getPlatform();
        body = self.entity.getRigidBody(self.entity);
        renderer = self.scene.getRenderer(self.scene);
        
        cam = renderer.camera;
        
        dir = Float3(cos(self.angle.y) * sin(self.angle.x),
                     sin(self.angle.y),
                     cos(self.angle.y) * cos(self.angle.x));
        
        cam.setDirection(cam, dir);
        
        right = Float3(sin(self.angle.x - PI/2.0),
                       0.0,
                       cos(self.angle.x - PI/2.0));
        
        cam.setUp(cam, right.cross(right, dir));
        
        resSpeed = self.speed;
        
        if platform.isKeyPressed(platform, Key.Space) {
            resSpeed = resSpeed * 2.0;
        };
        
        moveDir = Float3(sin(self.angle.x), 0.0, cos(self.angle.x));
        
        vel = Float3();
        
        if platform.isKeyPressed(platform, Key.A) {
            vel = vel - right*timestep*resSpeed;
        };
        
        if platform.isKeyPressed(platform, Key.D) {
            vel = vel + right*timestep*resSpeed;
        };
        
        if platform.isKeyPressed(platform, Key.W) {
            vel = vel + dir*timestep*resSpeed;
        };
        
        if platform.isKeyPressed(platform, Key.S) {
            vel = vel - dir*timestep*resSpeed;
        };
        
        vel.y = 0.0;
        
        oldVel = body.getLinearVelocity(body);
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
        
        body.setLinearVelocity(body, oldVel + vel);
        
        if platform.isKeyPressed(platform, Key.Space) and self.onFloor {
            vel = body.getLinearVelocity(body);
            vel.y = 10.0;
            body.setLinearVelocity(body, vel);
        };
        
        if platform.isLeftMouseButtonPressed(platform) {
            platform.setCursorVisible(platform, false);
            
            w = platform.getWindowWidth(platform);
            h = platform.getWindowHeight(platform);
            pos = platform.getMousePosition(platform);
            
            platform.setMousePosition(platform, Int2(w/2, h/2)); #TODO: Adding an extra ) does not raise an error.
            
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
            platform.setCursorVisible(platform, true);
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
        
        if platform.getMouseWheel(platform).y > 0.0 {
            self.zoom = self.zoom - timestep;
        } elif platform.getMouseWheel(platform).y < 0.0 {
            self.zoom = self.zoom + timestep;
        };
        
        self.zoom = max(min(self.zoom, 1.7), 0.3);
        
        cam.setFieldOfView(cam, self.zoom * 50.0);
        
        angVel = self.angVel;
        angVel = angVel * timestep * 0.1;
        
        if (angVel.x > -0.001) and (angVel.x < 0.001) {
            angVel.x = 0.0;
        };
        
        if (angVel.y > -0.001) and (angVel.y < 0.001) {
            angVel.y = 0.0;
        };
        self.angVel = angVel;
        
        cam.setPosition(cam, self.entity.transform.position + Float3(0.0, 1.5, 0.0));
        
        renderer.camera = cam;
    };
    
    preRender = function(self) {};
    postRender = function(self) {};
};


return class {
    __init__ = function(self, entity) {
        self.entity = entity;
        self.scene = entity:getScene();
        
        self.angle = Float2(PI, 0.0);
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
        
        shape = PhysicsShape();
        shape:setSphere(1.0);
        self.collisionGhost = physicsWorld:createGhostObject(shape, 0xFFFF );
        
        shape = PhysicsShape();
        shape:setSphere(0.75);
        self.attackGhost = physicsWorld:createGhostObject(shape, 0xFFFF );
    };
    
    __del__ = function(self) {
        self.scene:getPhysicsWorld():destroyGhostObject(self.attackGhost);
        self.scene:getPhysicsWorld():destroyGhostObject(self.collisionGhost);
        self.scene:getPhysicsWorld():destroyGhostObject(self.feetGhost);
    };
    
    handleInput = function(self) {};
    
    update = function(self) {};
    
    updateGhosts = function(self, viewDir) {
        dir2 = Float3(viewDir.x, 0.0, viewDir.z):normalize();
        
        feetTransform = self.entity.transform;
        pos = feetTransform.position;
        pos = Float3(pos.x, pos.y - 1.33, pos.z);
        feetTransform.position = pos;
        
        attackTransform = self.entity.transform;
        pos = attackTransform.position + dir2;
        attackTransform.position = pos;
        
        self.feetGhost:setTransform(feetTransform);
        self.collisionGhost:setTransform(self.entity.transform);
        self.attackGhost:setTransform(attackTransform);
    };
    
    fixedUpdate = function(self, timestep) {
        physicsWorld = self.scene:getPhysicsWorld();
        platform = getPlatform();
        body = self.entity:getRigidBody();
        renderer = self.scene:getRenderer();
        
        rigidBodies = self.feetGhost:getRigidBodyCollisions();
        self.onFloor = rigidBodies:getCount() != 0;
        
        rigidBodies = self.collisionGhost:getRigidBodyCollisions();
        i = 0;
        while i < rigidBodies:getCount() {
            entity = rigidBodies:get(i):getEntity();
            inst = entity:findScriptInstanceObj("resources/scripts/coin.rkt");
            
            if not isNil(inst) {
                inst.shrinking = true;
                #inst:onCollect();
                # TODO: Why won't "inst:onCollect()" work?
                # Unhandled script exception:
                #    Unknown member: 'scene'
                # In this function.
                # Throws a std::bad_alloc without showing the script exception.
            };
            
            i = i + 1;
        };
        
        if platform:isRightMouseButtonPressed() {
            rigidBodies = self.attackGhost:getRigidBodyCollisions();
            
            i = 0;
            while i < rigidBodies:getCount() {
                entity = rigidBodies:get(i):getEntity();
                inst = entity:findScriptInstanceObj("resources/scripts/monkey.rkt");
                
                if not isNil(inst) {
                    inst.attacked = true;
                };
                
                i = i + 1;
            };
        };
        
        cam = renderer.camera;
        
        quat = Quaternion(Float3(0.0, self.angle.x, 0.0));
        quat2 = Quaternion(Float3(self.angle.y, 0.0, 0.0));
        
        dir = quat2:toMatrix() * Float4(-1.0, -1.0, -1.0, 1.0);
        dir = quat:toMatrix() * dir;
        dir = Float3(dir.x, dir.y, dir.z) / dir.w;
        dir = dir:normalize();
        cam:setDirection(dir);
        
        self:updateGhosts(dir);
        
        right = quat:toMatrix() * Float4(1.0, 0.0, -1.0, 1.0);
        right = Float3(right.x, right.y, right.z) / right.w;
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
            
            angle = self.angle;
            angle.x = angle.x + 0.125*timestep*rel.x;
            angle.y = angle.y + 0.125*timestep*rel.y;
            angle.y = max(angle.y, 0.0);
            angle.y = min(angle.y, PI/4.0);
            self.angle = angle;
        } else {
            platform:setCursorVisible(true);
        };
        
        if platform:getMouseWheel().y > 0.0 {
            self.zoom = self.zoom - timestep;
        } elif platform:getMouseWheel().y < 0.0 {
            self.zoom = self.zoom + timestep;
        };
        
        self.zoom = max(min(self.zoom, 1.7), 0.3);
        
        cam:setFieldOfView(self.zoom * 50.0);
        
        "maxDistance = 5.0;
        hits = physicsWorld:castRay(self.entity.transform.position-dir, Float3(0.0)-dir, 999.0);
        
        if hits:getCount() == 0 {
            distance = maxDistance;
        } else {
            distance = hits:get(0).distance;
        };
        
        if distance < 1.2 {
            distance = maxDistance;
        };";
        distance = 10.0;
        
        cam:setPosition(self.entity.transform.position - dir*distance);
        
        renderer.camera = cam; #TODO: This is needed
    };
    
    preRender = function(self) {};
    postRender = function(self) {};
};


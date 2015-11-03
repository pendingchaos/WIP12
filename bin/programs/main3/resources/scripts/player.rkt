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
        shape:setCylinder(Axis.Y, 0.1, 0.4);
        self.feetGhost = physicsWorld:createGhostObject(shape, 0xFFFF ); #TODO: A space is required.
        
        self.wasPressedL = false;
        self.wasPressedR = false;
        
        self.focused = false;
        
        self.cube = 1;
    };
    
    __del__ = function(self) {
        self.scene:getPhysicsWorld():destroyGhostObject(self.feetGhost);
    };
    
    handleInput = function(self) {};
    
    update = function(self) {
        feetTransform = self.entity.transform;
        
        pos = feetTransform.position;
        pos = Float3(pos.x, pos.y - 1.1, pos.z);
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
        dir = dir:normalize();
        
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
        moveDir = dir:copy();
        moveDir.y = 0.0;
        moveDir = moveDir:normalize();
        
        if platform:isKeyPressed(Key.A) {
            vel = vel - right*timestep*resSpeed;
        };
        
        if platform:isKeyPressed(Key.D) {
            vel = vel + right*timestep*resSpeed;
        };
        
        if platform:isKeyPressed(Key.W) {
            vel = vel + moveDir*timestep*resSpeed;
        };
        
        if platform:isKeyPressed(Key.S) {
            vel = vel - moveDir*timestep*resSpeed;
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
            vel.y = 5.0;
            body:setLinearVelocity(vel);
        };
        
        if self.focused {
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
        };
        
        if platform:isKeyPressed(Key._1) {
            self.cube = 1;
        };
        
        if platform:isKeyPressed(Key._2) {
            self.cube = 2;
        };
        
        if platform:isKeyPressed(Key._3) {
            self.cube = 3;
        };
        
        if platform:isKeyPressed(Key._4) {
            self.cube = 4;
        };
        
        if platform:isRightMouseButtonPressed() {
            if not self.wasPressedR {
                self:handleClick(dir, false);
                self.wasPressedR = true;
            };
        } else {
            self.wasPressedR = false;
        };
        
        if platform:isLeftMouseButtonPressed() {
            if (not self.wasPressedL) and self.focused {
                self:handleClick(dir, true);
            };
            
            self.wasPressedL = true;
            self.focused = true;
        } else {
            self.wasPressedL = false;
        };
        
        if platform:isKeyPressed(Key.Escape) {
            self.focused = false;
        };
        
        platform:setCursorVisible(not self.focused);
        
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
        
        cam:setPosition(self.entity.transform.position + Float3(0.0, 0.5, 0.0));
        
        renderer.camera = cam;
    };
    
    preRender = function(self) {};
    postRender = function(self) {};
    
    rayVsAABB = function(rayOrigin, rayDir, aabb) {
        center = (aabb.min + aabb.max) / 2.0;
        extents = aabb.max - center;
        
        diff = rayOrigin - center;
        
        if (abs(diff.x) > extents.x) and ((diff.x*rayDir.x) >= 0.0) {
            return false;
        };
        
        if (abs(diff.y) > extents.y) and ((diff.y*rayDir.y) >= 0.0) {
            return false;
        };
        
        if (abs(diff.z) > extents.z) and ((diff.z*rayDir.z) >= 0.0) {
            return false;
        };
        
        fAWdU = Float3(abs(rayDir.x), abs(rayDir.y), abs(rayDir.z));
        
        f = rayDir.y*diff.z - rayDir.z*diff.y;
        if abs(f) > (extents.y*fAWdU.z + extents.z*fAWdU.y) {
            return false;
        };
        
        f = rayDir.z*diff.x - rayDir.x*diff.z;
        if abs(f) > (extents.x*fAWdU.z + extents.z*fAWdU.x) {
            return false;
        };
        
        f = rayDir.x*diff.y - rayDir.y*diff.x;
        if abs(f) > (extents.x*fAWdU.y + extents.y*fAWdU.x) {
            return false;
        };
        
        return true;
    };
    
    handleClick = function(self, dir, left) {
        app = getApp();
        chunk = app:getScript():getObj().chunk;
        
        pos = self.entity.transform.position + Float3(0.0, 0.5, 0.0);
        
        maxDist = 5.0;
        
        t = 0.0;
        done = false;
        while (t < maxDist) and not done {
            x = pos.x + dir.x*t;
            y = pos.y + dir.y*t;
            z = pos.z + dir.z*t;
            
            x = round(x) + 0.5;
            y = round(y) + 0.5;
            z = round(z) + 0.5;
            
            cube = chunk:getCube(x, y, z);
            
            if cube != 0 {
                if left {
                    chunk:setCube(x, y, z, 0);
                } else {
                    t = t - 0.05;
                    x = pos.x + dir.x*t;
                    y = pos.y + dir.y*t;
                    z = pos.z + dir.z*t;
                    x = round(x) + 0.5;
                    y = round(y) + 0.5;
                    z = round(z) + 0.5;
                    
                    chunk:setCube(x, y, z, self.cube);
                };
                
                done = true;
            };
            
            t = t + 0.05;
        };
        
        chunk:updateMeshes();
        chunk:updateRigidBodies(self.scene:getPhysicsWorld());
    };
};


import struct

class Entry:
    def __init__(self, category, type, file, line, function, message, variables, backtrace):
        self.category = category
        self.type = type
        self.file = file
        self.line = line
        self.function = function
        self.message = message
        self.variables = variables
        self.backtrace = backtrace

class Blog:
    def __init__(self, file):
        self.file = file
        
        if self.file.read(4) != "blog":
            print "Invalid binary log file."
            
            raise Exception();
        
        majorVersion = struct.unpack("B", self.file.read(1))[0]
        minorVersion = struct.unpack("B", self.file.read(1))[0]
        
        if majorVersion != 1 or minorVersion != 0:
            print "Unsupported binary log file version (%d.%d)." % (majorVersion, minorVersion)
            
            raise Exception();
        
        self.entries = []
    
    def read(self):
        while True:
            categoryLength = self.file.read(4)
            
            if categoryLength == "":
                return;
            
            categoryLength = struct.unpack("<L", categoryLength)[0]
            category = self.file.read(categoryLength)
            
            type = self.file.read(struct.unpack("<L", self.file.read(4))[0])
            file = self.file.read(struct.unpack("<L", self.file.read(4))[0])
            line = struct.unpack("<L", self.file.read(4))[0]
            function = self.file.read(struct.unpack("<L", self.file.read(4))[0])
            message = self.file.read(struct.unpack("<L", self.file.read(4))[0])
            
            variables = {}
            backtrace = []
            
            while True:
                op = struct.unpack("B", self.file.read(1))[0]
                
                if op < 11:
                    name = self.file.read(struct.unpack("<L", self.file.read(4))[0])
                
                if op == 0:
                    variables[name] = struct.unpack("B", self.file.read(1))[0]
                elif op == 1:
                    variables[name] = struct.unpack("b", self.file.read(1))[0]
                elif op == 2:
                    variables[name] = struct.unpack("H", self.file.read(2))[0]
                elif op == 3:
                    variables[name] = struct.unpack("h", self.file.read(2))[0]
                elif op == 4:
                    variables[name] = struct.unpack("L", self.file.read(4))[0]
                elif op == 5:
                    variables[name] = struct.unpack("l", self.file.read(4))[0]
                elif op == 6:
                    variables[name] = struct.unpack("Q", self.file.read(8))[0]
                elif op == 7:
                    variables[name] = struct.unpack("q", self.file.read(8))[0]
                elif op == 8:
                    variables[name] = struct.unpack("B", self.file.read(1))[0] != 0
                elif op == 9:
                    variables[name] = struct.unpack("f", self.file.read(4))[0]
                elif op == 10:
                    variables[name] = self.file.read(struct.unpack("<L", self.file.read(4))[0])
                elif op == 11:
                    depth = struct.unpack("<L", self.file.read(4))[0]
                    
                    for i in xrange(depth):
                        backtrace.append(self.file.read(struct.unpack("<L", self.file.read(4))[0]))
                elif op == 12:
                    break
            
            self.entries.append(Entry(category, type, file, line, function, message, variables, backtrace))

if __name__ == "__main__":
    file = open("../bin/log.bin")
    
    log = Blog(file)
    
    log.read()
    
    for entry in log.entries:
        print "[%s][%s] %s:%d:%s:" % (entry.category, entry.type, entry.file, entry.line, entry.function)
        print "    %s\n" % entry.message
        
        for name in entry.variables.keys():
            print "    %s: %s" % (name, str(entry.variables[name]))
        
        print "    Backtrace:"
        
        for function in entry.backtrace:
            print "        %s" % (function)
        
        print
    
    file.close()

#File to generate some of the macros in misc_macros.h

"""def gen(c):
    s = "#define __FOR_EACH"
    s += str(c)
    s += "(op"
    
    s += ", "
    
    if c == 0:
        s += "..."
    
    for i in xrange(c):
        s += "a"
        s += str(i+1)
        
        if i != c-1:
            s += ", "
    
    s += ")"
    
    for i in xrange(c):
        s += " op(a"
        s += str(i+1)
        s += ")"
    
    return s

for i in xrange(33):
    print gen(i)
"""

"""def gen(c):
    s = "#define __FOR_N"
    s += str(c)
    s += "(op)"
    
    for i in xrange(c):
        s += " op("
        s += str(i)
        s += ")"
    
    return s

for i in xrange(33):
    print gen(i)
"""

"""def gen(c):
    s = "#define __FOR_N_SEP"
    s += str(c)
    s += "(op, sep)"
    
    for i in xrange(c):
        s += " op("
        s += str(i)
        s += ")"
        
        if i != c-1:
            s += " sep "
    
    return s

for i in xrange(33):
    print gen(i)
"""

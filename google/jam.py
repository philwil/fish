#!/usr/bin/python

#https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881de


import random
base =""

# base is the list (as a string) of the working systems
# for x in range (2,len(foo2)): will produce the list
#
# ginen an input string
# we can see if we get a reply for node x
# if base[x] == "1" and ip[x] == "1"

def getStrMap(ip):
    global base
    op = ""
    ix = 0
    for x in range (0,len(ip)):
        if base[x] == "1" and ip[x] == "1":
            op += '1'
            ix+=1
    print ip + "==>" + op
    return op

    
def main():
    global base
    random.seed(379009)
    val = random.getrandbits(32)
    print val
    print " "
    print hex(val)
    print " "
    foo=bin(val)
    print" "
    print foo

    print" "
    print len(foo)

    foo2 = bin(0xff0000ff)
    print" "
    print foo2
    base=foo2

    print" "
    print len(foo2)
    foo3 = foo2[2:]
    
    for x in range (2,len(foo2)):
        print x,
        print " ",
        print foo2[x]

    print " "
    print foo3
    base = foo3

    op = getStrMap("11001100")
    op = getStrMap("11111100")
    op = getStrMap("111111111100")
    #print " "
    #print op
    
    
        
    
if __name__ == "__main__":
    main()
    

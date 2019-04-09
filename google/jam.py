#!/usr/bin/python

#https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881de


# possible solution
# send out a pattern 0101101110111101011011101111.. etc
# the response will mismatch at the first broken unit

# broken   0000101000000000000010000000
# pattern  0101101110111101011011101111.. etc
#response  0101011011110101101101111.. etc

#go forwards
# pattern  0101X01110111101011011101111.. etc

#go backwards
#             0101011011110101101101111.. etc
# pattern  0101X011101111010110X1101111.. etc
# we have the first two broken units
# now pad out response
#response  0101X01101111010110X1101111.. etc
# redo match but ignore know broken units

# pattern  0101101110111101011011101111.. etc
#response  0101X011X01111010110X1101111.. etc
# bingo we have the map of broken units


# nah rework it

# broken   0000101000000000000010000000000
# pattern  0000000000000001111111111111111
#response  00000000000000111111111111111
# we have 2 0's (first 16) missing and 1 1 missing 2nd 16
# pattern  0000000011111111000000001111111
#response  00000011111111000000011111111
# we have 2 missing  (first 8) missing and 1 missing third 8
# pattern  00001111000011110000111100001111
#response  00001100001111000111100001111
# we have 2 missing  (second 4 ) missing and 1 missing fifth 4
# pattern  00110011001100110011001100110011
#response  00110100110011001101100110011
# we have 1 missing  (third 2 , forth 2) missing and 1 missing eleveth 2

# break this down
#  16      ||       2        |     1             ||   
#   8      ||   2   |        |     1 |           ||   
#   4      ||   | 2 |   |    |   | 1 |     |     ||   
#   2      || | |1|1| | | |  | | |1| |  |  |  |  ||   
# fifth ping is
#             0    a    0    0    0    8    0
# broken   0000 1010 0000 0000 0000 1000 00000
# pattern  0000010100000000000010000000000
# response 0000110000000000000000000000
#      first  1 (@5)=  node 5 broken
#      second 1 (@6) = node 7 broken
#             0 (@20) = node 7 broken
#
# count the expected ones and zeros for each part
#  16 means that in the response the first 14 belong to the first part
#   1@14 2@15
# on the 8 count we count the 1s and 0 for each part but allow 2 to be missing
# we create the expected counts for the next set of divisions
#  1@6 2@8
#   and next 15 to the second part
#  8 means that in the response the first 14 belong to the first part
#   and next 15 to the second part


import random
import sys
base =""

# base is the list (as a string) of the working systems
# for x in range (2,len(foo2)): will produce the list
#
# given an input string
# we can see if we get a reply for node x
# if base[x] == "1" and ip[x] == "1"

#plan start with 1,2,4,8 all"1"
# keep going till reply does not match length
# have a known map and mask that with the attempts
# mask try map with known map
#if len known map is 1 less
# build a map of all devices all set to 1
# start with a scount of 0
# bits = 1
# set bits (1 or 0) on scount + "bits" devices if we get scount + "bits" responses
# we can set our next_base to scount+bits  responds increment bits ^2
# if we dont get a respone then oldbase to  scount and start with bits = 1 from there.
# if we get a no response with bits = 1 then oldbase plus scount is missing.
# set tha one to 0 and restart from there with bits = 1

def getStrMap(bp, ip):
    op = ""
    ix = 0
    for x in range (0,len(ip)):
        if bp[x] == "0" and ip[x] == "1":
            op += '1'
            ix+=1
        if bp[x] == "0" and ip[x] == "0":
            op += '0'
            ix+=1
    print ip + "==>" + op
    return op

def count1s(ip, max):
    num = 0
    for x in range (0,len(ip)):
        if max > 0:
            if ip[x] == '1':
                num += 1
                max -=1
            else:
                return num
        else:
            return num
        
    return num

def count0s(ip, max, debug=0):
    num = 0
    for x in range (0,len(ip)):
        if debug:
            print x,
            print "val=",
            print ip[x]
        if max > 0:
            if ip[x] == '0':
                num += 1
                max -=1
            else:
                return num
        else:
            return num

    return num
        
            
    
def getStrLen(ip,val='1'):
    op = ""
    for x in range (0,ip):
        op += val
    return op

# we expect 10 if we get 00 the first unit is broken if we get 11 second unit os broken
def getLMap(op, broken):
    idx = 1
    opmap = {}
    iidx = 0
    for idx in broken.keys():
        if broken[idx] == 2:
            # none broken
            opmap[iidx] = 1
            opmap[iidx+1] = 1
            op = op[2:]
            
        #only 1 is broken, find out which
        elif   broken[idx] == 1:
            if op[0] == '1':
                opmap[iidx] = 1
                opmap[iidx+1] = 0
            else:
                opmap[iidx] = 0
                opmap[iidx+1] = 1
            op = op[1:]

        elif   broken[idx] == 0:
            opmap[iidx] = 0
            opmap[iidx+1] = 0
        iidx += 2
    return opmap
            
def getMap(op, max):
    idx = 1
    opmap = {}
    while len(op) > 0:
        opmap[idx] = 0
        opmap[idx] = count1s(op, max) 
        op = op[opmap[idx]:]
        idx += 1
        opmap[idx] =0
        if len(op) > 0:
            opmap[idx] = count0s(op, max) 
            op = op[opmap[idx]:]
            idx += 1
    return opmap

    
def main():
    global base
    random.seed(379009)
    val = random.getrandbits(32)
    #print val
    #print " "
    #print hex(val)
    #print " "
    foo=bin(val)
    #print" "
    #print foo

    #print" "
    #print len(foo)

    foo2 = bin(0xff0000ff)
    #print" "
    #print foo2
    base=foo2

    #print" "
    #print len(foo2)
    foo3 = foo2[2:]
    
    #for x in range (2,len(foo2)):
    #    print x,
    #    print " ",
    #    print foo2[x]

    #print " "
    print foo3
    base = foo3
    t1 = getStrLen(32)
    print " "
    print t1
    t1 = getStrLen(8,'1')
    t1 = t1 + getStrLen(8,'0')
    t8 = t1 + t1
    t1 = getStrLen(4,'1')
    t1 = t1 + getStrLen(4,'0')
    t4 = t1 + t1 + t1 + t1
    t1 = getStrLen(2,'1')
    t1 = t1 + getStrLen(2,'0')
    t2 = t1 + t1 + t1 + t1  + t1 + t1 + t1 + t1
    
    
    print "t8 =[" +t8 +"]"
    print "t4 =[" +t4 +"]"
    print "t2 =[" +t2 +"]"

    base = '00001010000000000000100000000000'
    base = '00001110000000000000100000000000'
    #base = bin(0x0a00080)
    print base
    #sys.exit(0)
    print "try them out"
    
    op8 = getStrMap(base, t8)
    
    op4 = getStrMap(base, t4)
    op2 = getStrMap(base, t2)

    print " "

    print op8

    opt=op8
    print "opt =",
    print opt

    op8map = getMap(op8,8)
    op4map = getMap(op4,4)
    op2map = getMap(op2,2)

    print op8map
    print op4map
    print op2map
    lastop = ""
    for k in op2map.keys():
        if op2map[k] < 2:
            val = 2 - op2map[k]
            print "we have " ,
            print val ,
            print " broken units in area ",
            print k
            lastop += '10'
        else:
            lastop += '10'
    print lastop                

    #repeat
    op2l = getStrMap(base, lastop)
    print op2l
    
    op2lmap = getLMap(op2l,op2map)
    print op2lmap

if __name__ == "__main__":
    main()
    

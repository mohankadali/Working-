'''
import sys
sys.setrecursionlimit(500)
c = 0
def fun():
    global c
    c = c+1 
    print c
    fun()

fun()'''










def tower_of_hanoi(n,frm,to,aux):
    if(n == 1):
        print "Move first disk from  %c to rod %c" %(frm,to)
        return
    tower_of_hanoi(n-1,frm,aux,to)
    print "Move disk %d from rod %c to rod %c" %(n,frm,to)
    tower_of_hanoi(n-1,aux,to,frm)

tower_of_hanoi(5,'J','L','K')

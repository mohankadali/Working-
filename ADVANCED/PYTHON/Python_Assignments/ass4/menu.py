import ops
import os

options = [1,2,3]
while(1):
    print "1.Simple calc\t2.Scientific calc\t3.Exit"
    choice = input("Enter choice\n")
    if choice in options:
        if choice == 1:
            option2 = [1,2,3,4,5]
            print "1.Add\t2.Sub\t3.Mul\t4.Div\t5.Goback"
            operation = input("Enter required operation\n")
            if operation in option2:
                if operation == 5:
                    continue
                num1 = input("Enter num1\n")
                num2 = input("Enter num2\n")
                os.system("clear")
                if operation == 1:
                    ops.add(num1,num2)
                if operation == 2:
                    ops.sub(num1,num2)
                if operation == 3:
                    ops.mul(num1,num2)
                if operation == 4:
                    ops.div(num1,num2)
            else:
                print "Enter valid operation"
        if choice == 2:
            option3 = [1,2,3,4,5]
            
            print "1.sin\t2.cos\t3.power of\t4.square root\t5.goback"
            operation = input("Enter required operation\n")
            if operation in option3:
                if operation == 5:
                    continue
                num = input("Enter number\n")
                if operation == 3:
                    power = input("Enter power\n")
                os.system("clear")
                if operation == 1:
                    ops.sine(num)
                if operation == 2:
                    ops.cosine(num)
                if operation == 3:
                    ops.powerof(num,power)
                if operation == 4:
                    ops.squareroot(num)
            else:
                print "Enter valid operation"
        if choice == 3:
            exit( )
    else:
        print "Enter valid choice\n"

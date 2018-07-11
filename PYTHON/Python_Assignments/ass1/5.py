import random

sides = input("Enter sides of a dice\n")
times = input("Enter number of times to be rolled\n")

def dice_combination(times, sides):
    cnt = []
    for i in range(times):
        cnt.append(random.randint(1,sides))
    print cnt
dice_combination(times,sides) 

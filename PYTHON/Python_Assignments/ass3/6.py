inpgame = ["c","f"]

list1 = set()
list2 = set()
i = 0

num = input("Enter total number of players\n")
while(1):
    i = i + 1
    game = raw_input("Enter name of the game 'c' if Cricket, 'f' if football\n")
    name = raw_input("Enter the name of player\n")
    if game == 'c':
        list1.update([name])
    elif game == 'f':
        list2.update([name])
    else:
        print "Enter correct input"
    if i == num:
        break
print list1 & list2
print list1 | list2






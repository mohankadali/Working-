def fun(*argv):
    print argv[0]+" "+argv[1]+"\n"+argv[2]

title = raw_input("Enter title\n")
name = raw_input("Enter name\n")
message = raw_input("Enter msg\n")
fun(title.title(),name.title(),message)

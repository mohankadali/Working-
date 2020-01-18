try:
    f = open("textfile.txt")
    var = var1

except IOError:
    print "IO error"

except NameError:
    print "Name error"

except Exception:
    print "default error"

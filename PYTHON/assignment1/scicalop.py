import math

def add(a, b):
	return int(a) + int(b)

def sub(a, b):
	return int(a) - int(b)

def mul(a, b):
	return int(a) * int(b)

def div(a, b):
	return int(a) / int(b)

def sine(degrees):
	degrees = math.radians(degrees)
	return math.sin(degrees)

def cosine(degrees):
	degrees = math.radians(degrees)
	return math.cos(degrees)

def power(num, p):
	return math.pow(num, p)

def sqrot(num):
	return math.sqrt(num)




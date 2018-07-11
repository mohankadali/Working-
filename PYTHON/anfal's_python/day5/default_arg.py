class test:
	def __init__(self, a = "hello_world"):
		self.a = a
	def display(self):
		print (self.a)

obj = test()
obj.display()
obj = test("Welcome to my world")
obj.display()
		

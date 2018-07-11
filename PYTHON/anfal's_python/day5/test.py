class test:
	def __init__(self):
		self.variable = 'old'
		self.change(self.variable)
	def change(self, var):
		var = 'new'

obj = test()
print obj.variable
		

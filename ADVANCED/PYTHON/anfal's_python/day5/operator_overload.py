class D:
	def __init__(self, start):
		self.data = start
	def __sub__(self, other):
		return D(self.data - other)
	def displaydata(self):
		return self.data
x = D(7) 
y = x - 4
print y.displaydata()
	

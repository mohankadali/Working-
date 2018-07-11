class emp:
	#@staticmethod
	def accept_data(self):
		self.name = raw_input('Enter Employee Name:  ')
		self.company = raw_input('Company Name:  ')
		
	def display(self):
		print self.name
		print self.company

	@staticmethod
	def calls(self):
		a = emp()
		a.accept_data()
		a.display()


emp.calls('hi')

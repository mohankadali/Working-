import pdb
class Employee:
	emp_cnt = 0
	def __init__(self, salary):
		self.salary = salary
		Employee.emp_cnt += 1
#	def display_cnt(self):
#		return Employee.emp_cnt
	@staticmethod
	def display_cnt():
		return Employee.emp_cnt
		
	def display_salary(self):
		return self.salary
	def __del__(self):
		Employee.emp_cnt -= 1
emp1 = Employee(2000)
print emp1.display_cnt()
emp2 = Employee(5000)
print emp2.display_cnt()
print Employee.display_cnt()
print emp1.display_salary()
del emp1
print emp2.display_salary()
print emp2.display_cnt()


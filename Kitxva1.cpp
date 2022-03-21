#include <iostream>
using namespace std;
class Employee {
private:
	static int EmpCounter;
	string lastName;
	int age, salary;
protected:
	string name;
public:
	Employee(string n = "Avto", string ln = "Chachanidze", int a = 18, int s = 3000) :
		name(n), lastName(ln), age(a), salary(s) {
		EmpCounter++;
	}
	virtual ~Employee() {
		EmpCounter--;
		cout << "Employee Destructor" << endl;
	}
	static int getEmpCount() {
		return EmpCounter;
	}
	virtual void Work() {
		cout << name << " Is doing his/her stuff" << endl;
	}
	virtual ostream& operator << (ostream& out) {
		out << this->name << ' ' << this->lastName << ' ' << this->age << ' ' << this->salary << endl;
		return out;
	}
};

int Employee::EmpCounter = 0;
class Developer : public Employee {
private:
	string language;
public:
	Developer(string n = "Avto", string ln = "Chachanidze", int a = 18, int s = 3000, string l = "C++")
		: Employee(n, ln, a, s), language(l) {}
	~Developer() override {
		cout << "Developer Destructor" << endl;
	}
	void Work() override {
		cout << name << " Is writing code in " << language << endl;
	}
	ostream& operator << (ostream& out)override {
		Employee emp = static_cast<Employee>(*this); // ???
		emp.operator<<(out);
		//Employee::operator<<(out);
		out << this->language << endl;
		return out;
	}
};
int main() {
	Employee* emp = new Developer();
	emp->operator<<(cout);
	cout << emp->getEmpCount() << endl;
	emp->~Employee();
}
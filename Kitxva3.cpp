#include <iostream>
#include <string>
using namespace std;
__interface AbstractClass {
	void Eat()const;
	void Sleep()const;
	void Work()const;
	string Info();
};
class Employee : public AbstractClass {
private:
	string lastName;
	int age, salary;
	static int EmpCounter;
protected:
	string name;
public:
	Employee(string n = "Avto", string ln = "Chachandize", int a = 18, int s = 3000)
		: name(n), lastName(ln), age(a), salary(s) {
		EmpCounter++;
	}
	virtual ~Employee() {
		EmpCounter--;
	}
	static int getEmpCounter() {
		return EmpCounter;
	}
	void Eat()const override {
		cout << name << " Is eating" << endl;
	}
	void Sleep()const override {
		cout << name << " Is sleeping" << endl;
	}
	void Work()const override {
		cout << name << " Is doing his/her stuff" << endl;
	}
	string Info() override {
		string a = to_string(age);
		string s = to_string(salary);
		return name + ' ' + lastName + ' ' + a + ' ' + s + ' ';
	}
};
int Employee::EmpCounter = 0;
class Developer : public Employee {
	string language;
public:
	Developer(string n = "Avto", string ln = "Chachandize", int a = 18, int s = 3000, string l = "C++") :
		Employee(n, ln, a, s), language(l) {}
	~Developer()override = default;
	void Work()const override {
		cout << name << " Is writing code in " << language << endl;
	}
	string Info() override {
		//Employee* emp = this;
		//Employee* emp = static_cast<Employee*>(this);
		//Employee emp = static_cast<Employee>(*this);
		return Employee::Info() + ' ' + language;
	}
};
int main() {
	Developer dev;
	cout << dev.Info() << endl;
}
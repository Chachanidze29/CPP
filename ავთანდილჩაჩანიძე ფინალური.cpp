#include <iostream>
using namespace std;
class Employee {
public:
	virtual void printStatus() = 0;
	virtual int Salary() = 0;
}
class Staff : public Employee {
	double salary, plus;
public:
	Staff(double salary, double plus) : salary(salary), plus(plus) {}
	void printStatus()override {
		cout << "Staff" << endl;
	}
	int Salary()override {
		return salary + plus;
	}
};
class hourlyWorker : public Employee{
	double price;
	int hour;
public:
	Staff(double price, int hour) : price(price), hour(hour) {}
	void printStatus()override {
		cout << "hourlyWorker" << endl;
	}
	int Salary()override {
		return price * hour;
	}
};

int main() {
	Staff s1(100, 200);
	Staff s2(20, 300);
	hourlyWorker h1(11, 354);
	hourlyWorker h2(123, 233);
	s1.printStatus();
	cout << s1.Salary() << endl;
	h1.printStatus();
	cout << h1.Salary() << endl;
	Employee* emp[4]{ &s1,&s2,&h1,&h2 };
	for (int i = 0; i < 4; i++) {
		emp[i]->printStatus();
		cout << emp[i]->Salary() << endl;
	}
	delete[] emp;
}
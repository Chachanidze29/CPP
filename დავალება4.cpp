#include <iostream>
#include <string>
using namespace std;
class Employee {
public:
	Employee() = default;
	Employee(string name, int ID, double salary, pair<string, int>monthProfit) : name(name), ID(ID), salary(salary), monthProfit(monthProfit) {}
	~Employee() = default;
	string name;
	int ID;
	double salary;
	pair<string, int> monthProfit;
	virtual double getSalary()const = 0;
	virtual void inputInfo(istream& in) {
		in >> name >> ID >> salary >> monthProfit.first >> monthProfit.second;
	}
	virtual void printInfo(ostream&)const {
		cout << "Name " << name << " ID " << ID << " Salary " << salary << " Profit in "
			<< monthProfit.first << " Was " << monthProfit.second << endl;
	}
	friend istream& operator >> (istream&, Employee&);
	friend ostream& operator << (ostream&, const Employee&);
};
istream& operator >> (istream& in, Employee& obj) {
	obj.inputInfo(in);
	return in;
}
ostream& operator << (ostream& out, const Employee& obj) {
	obj.printInfo(out);
	out << "Whole salary in this month " << obj.getSalary() << endl;
	return out;
}
class Owner : public Employee {
protected:
	void inputInfo(istream& in) override {
		cout << "Enter Owner Information : ";
		Employee::inputInfo(in);
	}
	void printInfo(ostream& out)const override {
		cout << "Owner : " << endl;
		Employee::printInfo(out);
	}
public:
	Owner() = default;
	Owner(string name, int ID, double salary, pair<string, int> profit)
		: Employee(name, ID, salary, profit) {}
	~Owner() = default;
	double getSalary()const override {
		if (monthProfit.second <= 0)
			return salary;
		return salary + ((monthProfit.second * 60) / 100);
	}
};
class Chef : public Employee {
private:
	pair<string, size_t> CulinaryField;
	static int chefCounter;
protected:
	void inputInfo(istream& in) override {
		cout << "Enter Chef Information : ";
		Employee::inputInfo(in);
		cin >> CulinaryField.first >> CulinaryField.second;
	}
	void printInfo(ostream& out)const override {
		cout << "Chef : " << endl;
		Employee::printInfo(out);
		out << "This chef is good at " << CulinaryField.first << " And sold "
			<< CulinaryField.second << " Dishes of it with price of 10 Gel" << endl;
	}
public:
	Chef() = default;
	Chef(string name, int ID, double salary, pair<string, int> profit, pair<string, size_t>  CulinaryField)
		: Employee(name, ID, salary, profit), CulinaryField(CulinaryField) {
		chefCounter++;
	}
	~Chef() {
		chefCounter--;
	}
	double getSalary()const override {
		if (monthProfit.second <= 0)
			return salary;
		return salary + (((monthProfit.second * 20) / 100) / chefCounter) + CulinaryField.second * 10.;
	}
};
int Chef::chefCounter = 0;
class Waiter : public Employee {
private:
	size_t experience;
	double tips;
protected:
	void inputInfo(istream& in) override {
		cout << "Enter Waiter Information ";
		Employee::inputInfo(in);
		in >> experience >> tips;
	}
	void printInfo(ostream& out)const override {
		cout << "Waiter : " << endl;
		Employee::printInfo(out);
		out << "Experience " << experience << " Tips " << tips << endl;
	}
public:
	Waiter() = default;
	Waiter(string name, int ID, double salary, pair<string, int> profit, size_t experience, double tips)
		: Employee(name, ID, salary, profit), experience(experience), tips(tips) {}
	~Waiter() = default;
	double getSalary()const override {
		return salary + tips;
	}
};
int main() {
	Employee* emp1[6]{ new Owner("Avto",1101,5000,make_pair("march",3000)),
		new Chef("George",1110,3000,make_pair("March",3000),make_pair("Georgian dishes",5)),
		new Chef("Mary",1011,3000,make_pair("March",3000),make_pair("Italian dishes",3)),
		new Waiter("Sally",1111,1000,make_pair("March",3000),3,1000),
		new Waiter("Niko",1100,1000,make_pair("March",3000),4,1500),
		new Waiter("Nancy",1010,1000,make_pair("March",3000),1,500),
	};
	for (int i = 0; i < 6; i++) {
		cout << *emp1[i] << endl;
	}
	Owner ow; Chef ch1; Chef ch2; Waiter w1; Waiter w2; Waiter w3;
	Employee* emp[6];
	emp[0] = &ow; emp[1] = &ch1; emp[2] = &ch2; emp[3] = &w1; emp[4] = &w2; emp[5] = &w3;
	for (int i = 0; i < 6; i++) {
		cin >> *emp[i];
	}
	for (int i = 0; i < 6; i++) {
		cout << *emp[i];
	}
	delete[]emp1;
	delete[]emp;
}
#include <iostream>
#include <random>
using namespace std;
__interface AbstractEmplyee {
	void getPromotion()const;
	void Work()const;
	void printInfo()const;
};
class Employee : public AbstractEmplyee {
private:
	static int EmpCounter;
	string name, company;
	int age, salary;
public:
	Employee(string n, string c, int a, int s) :name(n), company(c), age(a), salary(s) {
		EmpCounter++;
	}
	~Employee() {
		EmpCounter--;
	}
	static int getEmpCounter() {
		return EmpCounter;
	}
	const string& getName()const {
		return name;
	}
	const string& getCompany()const {
		return company;
	}
	const int& getAge()const {
		return age;
	}
	const int& getSalary()const {
		return salary;
	}
	virtual void Work()const {
		cout << name << " Is Doing some stuff" << endl;
	}
	virtual void printInfo()const {
		cout << "Name " << name << " Company " << company << " Age "
			<< age << " Salary " << salary << endl;
	}
	void getPromotion ()const override {
		srand(time(NULL));
		if (rand() % 2 == 1)
			cout << name <<" got promoted" << endl;
		else
			cout << name <<" didn't get promoted" << endl;
	}
};
int Employee::EmpCounter = 0;
class Developer : public Employee,public AbstractEmplyee {
private:
	string language;
public:
	Developer(string n, string c, int a, int s, string l) :Employee(n, c, a, s) {
		language = l;
	}
	const string& getLanguage()const {
		return language;
	}
	void Work()const override {
		cout << getName() << " is writing code in " << language << endl;
	}
	void printInfo()const override {
		Employee emp = static_cast<Employee>(*this);
		emp.printInfo();
		cout << "Language that he/she knows " << language << endl;
	}
	void getPromotion()const override {
		srand(time(NULL));
		default_random_engine dre;
		uniform_int_distribution<int> dri(1, 100);
		if (50 > dri(dre))
			cout << getName() <<" got promoted" << endl;
		else
			cout << getName() <<" didn't get promoted" << endl;
	}
};
int main() {
	
}
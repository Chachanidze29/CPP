#include <iostream>
using namespace std;
class Contingent {
private:
	string name, last_name;
	int age;
protected:
	virtual void printInfo(ostream& out)const {
		out << "Name " << this->name << " Last name " << this->last_name << " Age " << this->age << endl;
	}
	virtual void inputInfo(istream& in) {
		in >> name >> last_name >> age;
	}
public:
	Contingent(string = "Avto", string = "Chachanidze", int = 18);
	friend ostream& operator << (ostream&, const Contingent&);
	friend istream& operator >> (istream&, Contingent&);
};
Contingent::Contingent(string name, string last_name, int age) : name(name), last_name(last_name), age(age) {}
ostream& operator << (ostream& out, const Contingent& obj) {
	obj.printInfo(out);
	return out;
}
istream& operator >> (istream& in, Contingent& obj) {
	obj.inputInfo(in);
	return in;
}
class Professor : public Contingent {
private:
	string position;
	int salary;
protected:
	void printInfo(ostream& out)const override {
		Contingent::printInfo(out);
		out << "Position " << this->position << " Salary " << this->salary << endl;
	}
	void inputInfo(istream& in)override {
		Contingent::inputInfo(in);
		in >> position >> salary;
	}
public:
	Professor(string = "Avto", string = "Chachanidze", int = 18, string = "Invited", int = 1500);
};
Professor::Professor(string name, string last_name, int age, string position, int salary) :
	Contingent(name, last_name, age), position(position), salary(salary) {}
class Student : public Contingent {
private:
	int course;
	int scholarship;
protected:
	void printInfo(ostream& out)const override {
		Contingent::printInfo(out);
		out << "Course " << this->course << " Scholarship " << this->scholarship << endl;
	}
	void inputInfo(istream& in)override {
		Contingent::inputInfo(in);
		in >> course >> scholarship;
	}
public:
	Student(string = "Avto", string = "Chachanidze", int = 18, int = 1, int = 200);
};
Student::Student(string name, string last_name, int age, int course, int scholarship) :
	Contingent(name, last_name, age), course(course), scholarship(scholarship) {}
int main() {
	Contingent* arr[]{ new Professor,new Student };
	size_t size = sizeof(arr) / sizeof(Contingent*);
	for (int i = 0; i < size; i++) {
		cin >> *arr[i];
	}
	for (int i = 0; i < size; i++) {
		cout << *arr[i];
	}
	size_t size2 = 2;
	Contingent* c = new Student[size2]; //რატომ არ მუშაობს ამგვარად	
	for (int i = 0; i < size2; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < size2; i++) {
		cout << c[i];
	}

}
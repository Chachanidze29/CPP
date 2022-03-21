#include <iostream>
using namespace std;
class Date {
public:
	size_t day, month, year;
	Date(size_t, size_t, size_t);
	void checkDate(size_t&, size_t&, size_t&);
	void print()const;
};
Date::Date(size_t d, size_t m, size_t y) : day(d),month(m),year(y){
	checkDate(d, m, y);
}
void Date::checkDate(size_t& d, size_t& m, size_t& y) {
	int* Month = new(nothrow) int[13]{ 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	//თვეების შემოწმება
	if (m <= 0 || m > 12) {
		month = 1;
		cout << "Wrong input of month. Set to month 1" << endl;
	}
	//წლების შემოწმება
	if (y < 1920) {
		year = 1920;
		cout << "Wrong input of year. Set to year 1920" << endl;
	}
	else if (y > 2020) {
		year = 2020;
		cout << "Wrong input of year. Set to year 2020" << endl;
	}
	//დღეების შემოწმება
	if (m != 2) {
		if (d <= 0 || d > Month[month]) {
			cout << "Wrong input of day. Set to last day of month" << endl;
			day = Month[month];
		}
	}
	else {
		int k = (year % 4 == 0) ? 29 : 28;
		if (d <= 0 || d > k) {
			cout << "Wrong input of day. Set to last day of month" << endl;
			day = k;
		}
	}
}
void Date::print()const {
	cout << "Year " << year << " Month " << month << " Day " << day << endl;
}
class Footballer {
	string name;
	string clubName;
	size_t price;
	Date birthDate;
public:
	Footballer(string, string, size_t, size_t, size_t, size_t);
	int getPrice()const;
	void print()const;
};
Footballer::Footballer(string n, string cn, size_t p, size_t d, size_t m, size_t y) : birthDate(d, m, y) {
	name = n; clubName = cn; price = p;
}
int Footballer::getPrice()const {
	return this->price;
}
void Footballer::print()const {
	cout << "Footballers name " << name << " His current club " << clubName << " His price " << price
		<< " His birthdate ";
	birthDate.print();
}
int main() {
	Footballer f1("Messi", "Barcelona", 20000000, 28, 2, 2004);
	f1.print();
}
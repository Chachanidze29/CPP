#include <iostream>
#include <typeinfo>
using namespace std;
template <typename obj_type>
void Square(const obj_type& obj) {
	string str = typeid(obj).name();
	if (str == "int") {
		for (int i = 1; i <= obj; i++) {
			cout << i * i << ' ';
			if (i % 5 == 0)
				cout << endl;
		}
	}
	else if (str == "double") {
		for (double i = 0.1; i <= obj; i += 0.1) {
			static int k = 0;
			cout << i * i << ' ';
			if (k % 5 == 4)
				cout << endl;
			k++;
		}
	}
}
int main() {
	int iNum = 100;
	double dNum = 100.;
	Square(iNum);
	cout << endl << endl << endl;
	Square(dNum);
}
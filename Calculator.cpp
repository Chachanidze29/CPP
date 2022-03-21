#include <iostream>
using namespace std;
void Calculator(double*, double*, char*);
int main() {
	double* num1 = new(nothrow) double;
	double* num2 = new(nothrow) double;
	char* sym = new(nothrow) char;
	Calculator(num1, num2, sym);
}
void Calculator(double* a, double* b, char* s) {
	while (true) {
		cout << "shemoitanet ori ricxvi : (programis dasasruleblad gamoiyenet Ctrl Z klavishebis kombinacia) ";
		cin >> *a >> *b;
		if (cin.fail()) {
			cout << "aseti ricxvebi ar arsebobs ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');continue;
		}
		cout << "shemoitanet operatori : ";
		cin >> *s;
		switch (*s) {
		case '+':
			cout << *a + *b; break;
		case '-':
			cout << *a - *b; break;
		case '/':
			if (*b == 0) {
				cout << "0ze gayofa ar sheidzleba"; break;
			}
			else cout << *a / (*b); break;
		case '*':
			cout << *a * (*b); break;
		default:
			cout << "aseti operatori ar arsebobs"; break;
		}
		cout << endl;
	}
}
#include <iostream>
using namespace std;
int sum(int);
int factorial(int num);
int main() {
	int num, res;
	cin >> num;
	res = sum(num);
	cout <<"1-dan "<<num<<"-mde ricxvebis jami = " <<res << endl;
	cout <<"1-dan "<<num<<"-mde ricxvebis namravli = " <<factorial(num) << endl;
}
int sum(int num) {
	if (num != 0) {
		return (num + sum(num - 1)); //რეკურსია
	}
	else
		return num;
}
int factorial(int num) {
	int sum = 1;
	while (num != 0) {  //while ციკლი
		sum *= num;
		--num;
	}
	return sum;
}
#include <iostream>
using namespace std;
int SumRec(int* arr, const size_t& N, size_t ind = 0, int Sum = 0) {
	if (ind == N - 1) {
		return Sum + arr[ind];
	}
	return arr[ind] + SumRec(arr, N, ind + 1, Sum);
}
int countRec(int* arr, const size_t& N, const int& value, size_t ind = 0) {
	if (ind == N) {
		return 0;
	}
	if (arr[ind] == value) {
		return countRec(arr, N, value, ind + 1) + 1;
	}
	return countRec(arr, N, value, ind + 1);
}
int FibRec(const int& n) {
	if (n <= 1) {
		return 1;
	}
	return FibRec(n - 1) + FibRec(n - 2);
}
int USG(const int& x, const int& y) {
	if (x == y) {
		return x;
	}
	if (x > y) {
		return USG(x - y, y);
	}
	return USG(y, y - x);
}
int main() {
	int* arr = new int[5]{ 1,2,5,5,5 };
	int sum = SumRec(arr, 5);
	int count = countRec(arr, 5, 5);
	cout << sum << endl;
	cout << count << endl;
	cout << FibRec(5) << endl;
	cout << USG(24, 36) << endl;
}
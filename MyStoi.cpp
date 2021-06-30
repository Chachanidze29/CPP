#include <iostream>
#include <chrono>
using namespace std;
int Mystoi(string&);
int main() {
	auto start = chrono::steady_clock::now();
	string word= "1234567899";
	int num1 = Mystoi(word);
	cout << num1 << endl;
	auto end = chrono::steady_clock::now();
	double elapsed_time = double(chrono::duration_cast<chrono::nanoseconds>(end-start).count());
	cout << "Elapsed time " << elapsed_time/1e9 << endl;
}
int Mystoi(string& w) {
	int num = 0, pow = 1;
	for (int i = w.size()-1; i >=0; i--) {
		if (w[i] >= '0' && w[i] <= '9') {
			num += (w[i] - '0') * pow;
			pow *= 10;
		}
		else {
			cout << "Ivalid input " << endl; return 0;
		}
	}
	return num;
}
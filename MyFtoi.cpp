#include <iostream>
#include <chrono>
#include <string>
using namespace std;
struct timer {
	chrono::time_point<chrono::steady_clock>start, end;
	chrono::duration<float>duration;
	timer() {
		start = chrono::high_resolution_clock::now();
	}
	~timer() {
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		cout << "Timer took " << ms << " milliseconds" << endl;
	}
};
double MyFtoi(string&);
int main() {
	timer timer;
	string word = "2.512522";
	double num=MyFtoi(word);
	cout << num << endl;
}
double MyFtoi(string& w) {
	double num = 0;
	int dot_index = 0;
	for (int i = 0; i < w.size(); i++) {
		if (w[i] == '.')
			dot_index = i;
	}
	for (int i = dot_index-1; i >=0; i--) {
		if (w[i] >= '0' && w[i] <= '9') {
			static int pow = 1;
			num += (w[i] - '0') * pow;
			pow *= 10;
		}
		else {
			cout << "Invalid input" << endl; return 0;
		}
	}
	for (int i = dot_index+1; i < w.size(); i++) {
		if (w[i] >= '0' && w[i] <= '9') {
			static double pow = 0.1;
			num += (w[i] - '0') * pow;
			pow *= 0.1;
		}
		else {
			cout << "Invalid input" << endl; return 0;
		}
	}
	return num;
}
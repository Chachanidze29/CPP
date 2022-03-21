#include "MyList.h"

size_t N = 1000000000;

int main() {
	auto t = time(nullptr);
	vector<int> vec(N);
	for (int i = 0; i <N; i++) {
		vec[i] == 1;
	}
	cout << time(nullptr)-t << endl;
	MyList lst(N);
	for (int i = 0; i < N; i++) {
		lst.insert(i, 1);
	}
	cout << time(nullptr)-t << endl;
}
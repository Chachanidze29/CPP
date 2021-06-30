#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main() {
	clock_t tstart = clock();
	int a, b, r;
	cout << "Enter 2 Integers : ";
	cin >> a >> b;
	if (b > a) swap(a, b);
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	cout << "GCD(A,B) = " << (a < 0 ? -a : a) << endl;
	printf("time taken: %.2fs\n ", (double)(clock() - tstart) / CLOCKS_PER_SEC);
}





























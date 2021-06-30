#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main() {
	clock_t tstart = clock();
	double k, f0(1), f1(1), fn = f0 + f1;
	cin >> k;
	for (; fn <= k; cout <<fixed<<setprecision(0) <<fn << ' ', f0 = f1, f1 = fn, fn = f0+f1);
	cout << endl;
	printf("time taken: %.2fs\n ", (double)(clock() - tstart) / CLOCKS_PER_SEC);
}





























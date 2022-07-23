#include "mQueue.h"
#include <ctime>
#include <string>
#include <random>
#include <cstdlib>
#include "mPair.h"
const unsigned N = 10;

double rDouble(int a, int b) {
	 return a + (double(rand()) / RAND_MAX) * (b - a + 1);
}
int rInt(int a, int b) {
	 return a + rand() % (b - a + 1);
}

int main() {
	 srand(time(nullptr));
	 int i;
	 cout << "===================== type int =====================\n";

	 mQueue<int> qInt;
	 cout << "Before inserting objects: " << qInt;
	 for (i = 0; i < N; i++) {
		  qInt.push(rInt(1, 20));
	 }

	 cout << "values in Queue:\n\t" << qInt << endl;	

	 cout << "Before removing objects first value: \t" << qInt.front() << endl;
	 qInt.pop();	 
	 cout << "\nAfter removing objects top value:\t" << qInt.front() << endl;

	 cout << "\n===================== type double =====================\n";

	 mQueue<double> qDouble;
	 cout << "Before inserting objects:" << qDouble;
	 for (i = 0; i < N; i++) {
		  qDouble.push(rDouble(1, 20));
	 }

	 cout << "values in Queue:\n\t" << qDouble << endl; 
	
	 cout << "Before removing objects first value: \t" << qDouble.front() << endl;
	 qDouble.pop();
	 cout << "\nAfter removing objects top value: \n" << qDouble << endl;

	 cout << "\n===================== type mPair =====================\n";
	 mQueue<mPair<string, int>> qPair;
	 cout << "Before inserting objects:" << qPair;
	 for (i = 0; i < N; i++)
	 {
		  mPair<string, int> pair("Value_" + to_string(i), rInt(1, 20));
		  qPair.push(pair);
	 }

	 cout << "Before removing objects first value: \n\t" << qPair << endl;
	 qPair.pop();
	 cout << "\nAfter removing objects top value: \n" << qPair << endl;

	 return 0;
}

#include "Staque.h"
int main() {
	srand(time(NULL));
	Staque deq;
	for (int i = 0; i < 10; i++) {
		deq.Insert(rand());
	}
	cout << deq;
	deq.Delete(5);
	cout << deq;
}
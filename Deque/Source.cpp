#include "mDeque.h"

int main()
{
	 mDeque<int> m;
	 cout << m << endl;

	// 30 40 50 60 70
	 m.pushFront(50);
	 m.pushBack(60);
	 m.pushFront(40);
	 m.pushBack(70);
	 m.pushFront(30);

	 cout << "======================\n";
	 cout << m.getSize() << endl;
	 cout << m << endl;
	 cout << "======================\n";
	 cout << m.getFront() << endl;
	 m.popFront();
	 cout << m.getFront() << endl;
	 cout << "======================\n";
	 cout << m.getBack() << endl;
	 m.popBack();
	 cout << m.getBack() << endl;
	 cout << "======================\n";
	 cout << m.getSize() << endl;

	 mDeque<int> m1(m);
	 cout << "m1: " << m1 << endl;

	 mDeque<int> m2;
	 m2 = m;
	 cout << "m2: " << m2 << endl;

	 cout << endl;

}
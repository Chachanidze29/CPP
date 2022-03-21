#include "BST.h"
int main() {
	srand(time(NULL));
	BST<int> b;
	cout << "Element insertion in BST : " << endl;
	for (int i = 0; i < 10; i++) {
		b.insert(rand());
	}
	cout << "Printing elements using preorder : " << endl;
	b.preorder(cout);
	cout << "Element removing : " << endl;
	b.remove(1);
	cout << "searching Element : " << endl;
	b.search(123) ? cout << "Element found" << endl : cout << "Element not found" << endl;
	b.empty() ? cout << "BST is emoty" << endl : cout << "BST not empty" << endl;
}
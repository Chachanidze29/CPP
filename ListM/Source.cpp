#include "MyList.h"
MyList::MyList(size_t size) {
	bSize = size;
	cSize = 0;
	buff = new(nothrow) int[size];
}
MyList::MyList(MyList& obj) {
	bSize = obj.bSize;
	cSize = obj.cSize;
	buff = new(nothrow) int[bSize];
	for (int i = 0; i < cSize; ++i) {
		buff[i] = obj.buff[i];
	}
}
MyList::~MyList() {
	delete[] buff;
}
int MyList::getSize()const {
	return bSize;
}
bool MyList::empty()const {
	return cSize == 0;
}
void MyList::insert(const int ind, const int el) {
	if (cSize == bSize) {
		cerr << " XXXX buffer is FULL!!! XXXX" << endl;
		return;
	}
	if (ind <0 || ind > bSize) {
		cerr << " XXXX out of RANGE!!! XXXX" << endl;
		return;
	}
	for (int i = cSize; i > ind; --i)
		buff[i] = buff[i - 1];
	buff[ind] = el;
	cSize++;
}
void  MyList::pop(const int ind) {
	if (0 == cSize) {
		cerr << "*** Array is Empty !!! ****\n";
		return;
	}
	if (ind < 0 || ind > cSize) {
		cerr << "*** Out of range !!! ****\n";
		return;
	}
	for (int i = ind; i < cSize; i++) {
		buff[i] = buff[i + 1];
	}
	cSize--;
}
MyList& MyList:: operator = (const MyList& obj) {
	if (this != &obj) {
		if (bSize != obj.bSize) {
			delete[] buff;
			bSize = obj.bSize;
			buff = new int[bSize];
		}
		cSize = obj.cSize;
		for (int i = 0; i < cSize; i++) {
			buff[i] = obj.buff[i];
		}
	}
	return *this;
}
ostream& operator << (std::ostream& out, MyList& obj) {
	out << "Full Number " << obj.bSize << endl;
	out << "Element Number " << obj.cSize << endl;
	for (int i = 0; i < obj.cSize; ++i) {
		out << obj.buff[i] << ' ';
	}
	cout << endl;
	return out;
}
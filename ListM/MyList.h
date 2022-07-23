#pragma once
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
class MyList {
	int bSize;
	int cSize;
	int* buff;
public:
	MyList(size_t = 100);
	MyList(MyList&);
	~MyList();
	int getSize()const;
	bool empty()const;
	void insert(const int, const int);
	void pop(const int);
	MyList& operator = (const MyList&);
	friend std::ostream& operator << (std::ostream&, MyList&);
};

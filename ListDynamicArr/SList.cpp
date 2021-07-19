#include"SList.h"

SList::SList(int Size) : mSize(Size), cSize(0) {
	 dArray = new (nothrow) int[mSize];
}

SList::SList(SList& el) : mSize(el.mSize), cSize(el.cSize) {
	 dArray = new (nothrow) int[mSize];
	 for (int i = 0; i < cSize; i++) {
		  dArray[i] = el.dArray[i];
	 }
}

SList::~SList() {
	 delete[] dArray;
}

bool SList::empty() const {
	 return cSize == 0;
}

void SList::insert(const int Value, const int Index) {
	 if (mSize == cSize) {
		  cerr << "*** Array is Full !!! ****\n";
		  return;
	 }
	 if (Index < 0 || Index > cSize) {
		  cerr << "*** Out of range !!! ****\n";
		  return;
	 }
	 for (int i = cSize; i > Index; i--) {
		  dArray[i] = dArray[i - 1];
	 }
	 dArray[Index] = Value;
	 cSize++;
}
void SList::eraze(const int Index) {
	 if (0 == cSize) {
		  cerr << "*** Array is Empty !!! ****\n";
		  return;
	 }
	 if (Index < 0 || Index > cSize) {
		  cerr << "*** Out of range !!! ****\n";
		  return;
	 }
	 for (int i = Index; i < cSize; i++) {
		  dArray[i] = dArray[i + 1];
	 }
	 cSize--;
}

SList& SList::operator=(const SList& obj) {
	 if (this != &obj) {
		  if (mSize != obj.mSize) {
			   delete[] dArray;
			   mSize = obj.mSize;
			   dArray = new (nothrow) int[mSize];
		  }
		  cSize = obj.cSize;
		  for (int i = 0; i < cSize; i++) {
			   dArray[i] = obj.dArray[i];
		  }
	 }
	 return *this;
}

ostream& operator<<(ostream& out, SList& obj) {
	 out << "Size of dArray is " << obj.cSize << "\n";
	 for (int i = 0; i < obj.cSize; i++) {
		  out << obj.dArray[i] << "  ";
	 }
	 return out;
}

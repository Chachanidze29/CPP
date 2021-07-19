/* ამ ფაილში ხდება template-ის მეშვეობით კლასის განზოგადება
 * სხვადასხვა ტიპის მიმართ მისი გამოყენების მიზნით.           */

#include "H_Lib.h"

template <typename obj_type>
class TList {
	 int mSize;      // მასივში ობიექტების საერთო რაოდენობა
	 int cSize;      // ჩაწერილი ობიექტების რაოდენობა
	 obj_type sArray[N]; // მასივი ელემენტების შესანახად
public:
	 TList(int size = 0)
	 {
		  // თუ მომხმარებელმა არასწორად მიუთითა ობიექტების რაოდენობა 
		  while (0 > size && size > N)
		  {
			   int tmp;
			   cout << "*** Enter valid number (range [0, " << N << "]): ";
			   cin >> tmp;
		  }
		  mSize = size;
		  cSize = 0;
	 }

	 TList(TList& obj)
	 {
		  mSize = obj.mSize;
		  cSize = obj.cSize;
		  for (int i = 0; i < cSize; i++) {
			   sArray[i] = obj.sArray[i];
		  }
		  
	 }

	 ~TList() {}

	 void resize(int newSize)
	 {
		  // თუ მომხმარებელმა არასწორად მიუთითა ობიექტების რაოდენობა 
		  while (0 >= newSize && newSize > N)
		  {
			   cout << "Enter valid number (range [0, " << N << "]): ";
			   cin >> newSize;
		  }
		  mSize = newSize;
	 }

	 bool empty() const
	 {
		  return cSize == 0;
	 }

	 void insert(const int index, const obj_type value)
	 {
		  if (cSize == mSize) {
			   cerr << "*** Array is Full !!! ****\n";
			   return;
		  }
		  if (index < 0 || index > cSize) {
			   cerr << "*** Out of range !!! ***\n";
			   return;
		  }
		  for (int i = cSize; i > index; i--) {
			   sArray[i] = sArray[i - 1];
		  }
		  sArray[index] = value;
		  cSize++;
	 }

	 void eraze(const int index) {
		  if (0 == cSize) {
			   cerr << "*** Array is Empty !!! ****\n";
			   return;
		  }
	 	
		  if (index < 0 || index >= cSize) {
			   cerr << "*** Out of range !!! *** \n";
			   return;
		  }

		  cSize--;
		  for (int i = index; i < cSize; i++) {
			   sArray[i] = sArray[i + 1];
		  }
	 }

	 SList& operator=(const TList& obj) {
		  if (this != &obj) {
			   cSize = obj.cSize;
			   for (int i = 0; i < cSize; i++) {
					sArray[i] = obj.sArray[i];
			   }
		  }
		  return *this;
	 }

	 // გადავტვირთოთ [] (ინდექსირების) ოპერატორი
	 obj_type & operator[](int i) {
		  if (0 < cSize && i > cSize) {
			   cout << "Index out of bounds" << endl;
			   // დავაბრუნოთ მასივის პირველი ელემენტი
			   return sArray[0];
		  }
		  // დავაბრუნოთ მასივის მითითებული ელემენტი
		  return sArray[i];
	 }

	 /* შესაძლებელია ამ დაწილის დაკომენტარება მომდევნო დაკომენტარებული ნაწილის გახსნა */
	 friend ostream& operator<<(ostream& out, TList& obj) {
		  out << "Size of sArray is " << obj.cSize << "\n";
		  for (int i = 0; i < obj.cSize; i++) {
			   out << obj.sArray[i] << "  ";
		  }
		  return out;
	 } 
	 friend Tlist& operator + (const obj_type& num) {
		 for (int i = 0; i < cSize; i++) {
			 sArray[i] += num;
		 }
		 return *this;
	 }
};

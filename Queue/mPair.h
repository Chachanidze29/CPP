#pragma once
// ამ ფაილში განსაზღვრულია წყვილების სიმრავლე
#include <iostream>
using namespace std;
template <typename T1, typename T2>
class mPair
{
	 T1 First;
	 T2 Second;
public:
	 mPair(T1 val1, T2 val2) : First(val1), Second(val2) {}
	 friend ostream& operator<<(ostream& out, mPair& obj) {		  
		  out << "\tFirst: " << obj.First << ",  Second: " << obj.Second << endl;
		  return out;
	 }
};
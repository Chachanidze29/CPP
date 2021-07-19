// ამ ფაილში სტატიკური მასივის გამოყენებით იქმნება დინამიური სტრუქტურა
// მასში განსაზღვრული რამდენიმე ფუნქციით, რომელიც იძლევა გარკვეული
// რაოდენობის ელემენტების (1024) შენახვის საშუალებას.
#pragma once
#include <iostream>
using namespace std;
#ifndef SLIST
#define SLIST
class SList {
	 int mSize;      // ელემენტების საერთო რაოდენობა
	 int cSize;      // ჩაწერილი ელემენტების რაოდენობა
	 int* dArray;    // მასივი ელემენტების შესანახად
public:
	 SList(int = 1024);
	 SList(SList&);
	 ~SList();
	 bool empty() const;
	 void insert(const int, const int);
	 void eraze(const int);
	 SList& operator=(const SList&);
	 friend ostream& operator<<(ostream&, SList&);
};
#endif // SLIST

#pragma once
#include <iostream>
using namespace std;
template <typename obj_type = int>
class mNode {
public:
	obj_type data;
	mNode* next;
	mNode* prev;
	mNode<obj_type>(obj_type value, mNode* _prev = nullptr, mNode* _next = nullptr) :
		data(value),
		prev(_prev),
		next(_next)
	{}
};
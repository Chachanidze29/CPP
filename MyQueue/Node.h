#pragma once
#include <iostream>
using namespace std;
template<typename obj_type>
class Node {
public:
	obj_type data;
	Node* next;
	Node<obj_type>(obj_type data) : data(data) {
		next = nullptr;
	}
};
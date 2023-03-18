#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
template <typename DataType>
class Node {
private:
	template<typename DataType>
	friend class BST;
	DataType data;
	Node* left;
	Node* right;
public:
	Node();
	Node(DataType data);
};
template <typename DataType>
Node<DataType>::Node() : left(nullptr), right(nullptr) {}
template <typename DataType>
Node<DataType>::Node(DataType data) : data(data), left(nullptr), right(nullptr) {}
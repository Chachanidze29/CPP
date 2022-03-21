#pragma once
#include <iostream>

using namespace std;

// data structure that represents a node in the tree
struct Node {
	int data; // holds the key
	Node* parent; // pointer to the parent
	Node* left; // pointer to left child
	Node* right; // pointer to right child
	int color; // 1 -> Red, 0 -> Black
};
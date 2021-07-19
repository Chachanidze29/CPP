#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node() : next(nullptr),data(0) {}
	Node(int data,Node* next = nullptr) : data(data), next(next) {}
};
class HashTable {
private:
	typedef Node* pNode;
	typedef Node sNode;
	size_t size;
	Node** arr;
public:
	HashTable(size_t size) : size(size + size / 3) {
		arr = new Node * [this->size];
		for (int i = 0; i < this->size; i++) {
			arr[i] = nullptr;
		}
	}
	~HashTable() {
		for (int i = 0; i < size; i++) {
			if (arr[i] != nullptr) {
				pNode curr = arr[i], next = nullptr;
				while (curr != nullptr) {
					next = curr->next;
					delete curr;
					curr = next;
				}
			}
		}
		delete[] arr;
	}
	size_t getSize()const {
		return size;
	}
	size_t Hash(int item) {
		return item % this->size;
	}
	void Insert(int item) {
		size_t ind = Hash(item);
		if (arr[ind] == 0) {
			arr[ind] = new sNode(item);
		}
		else {
			arr[ind] = new sNode(item, arr[ind]);
		}
	}
	bool Check(int item) {
		size_t ind = Hash(item);
		pNode tmp = arr[ind];
		while (tmp != nullptr) {
			if (tmp->data == item)
				return true;
			tmp = tmp->next;
		}
		return false;
	}
	bool Search(pNode curr, int item) {
		size_t ind = Hash(item);
		curr = arr[ind];
		while (curr != nullptr) {
			if (curr->data == item)
				return true;
			curr = curr->next;
		}
		return false;
	}
	void Delete(int item) {
		size_t ind = Hash(item);
		pNode parent = nullptr, curr = arr[ind];
		if (curr->data == item) {
			delete curr;
			arr[ind] = nullptr;
			return;
		}
		parent = curr;
		curr = curr->next;
		while (curr != nullptr) {
			if (curr->data == item) {
				parent->next = curr->next;
				delete curr;
				return;
			}
			parent = curr;
			curr = curr->next;
		}
	}
	friend ostream& operator << (ostream& out, const HashTable& obj) {
		for (int i = 0; i < obj.size; i++) {
			if (obj.arr[i] == nullptr) { continue; }
			pNode tmp = obj.arr[i];
			cout << i << " -----> ";
			while (tmp != nullptr) {
				cout << setw(7) << tmp->data;
				tmp = tmp->next;
			}
			cout << endl;
		}
		return out;
	}
};
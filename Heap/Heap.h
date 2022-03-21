#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename obj_type>
class Heap {
private:
	int size;
	vector<obj_type> heap;
	void Up(int& index) {
		int p = (index - 1) / 2;
		if (p >= 0 && heap[p] > heap[index]) {
			swap(heap[p], heap[index]);
			Up(p);
		}
	}
	void Down(int& index) {
		int c = index * 2;
		int left = c + 1 < size ? c + 1 : -1;
		int	right = c + 2 < size ? c + 2 : -1;
		if (left > 0) {
			swap(heap[index], heap[left]);
			down(left);
		}
	}
public:
	Heap() = default;
	void Insert(obj_type value) {
		heap.push_back(value);
		Up(size);
		size++;
	}
	void Delete() {
		if (size == 0)
			return;
		heap[0] = heap[--size];
		heap.pop_back();
		Down(0);
	}
	friend ostream& operator << (ostream& out, const Heap& obj) {
		if (obj.size > 0) {
			for (auto m : obj.heap)
				out << m << ' ';
			out << endl;
		}
		return out;
	}
};
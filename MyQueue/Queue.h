#include "Node.h"
template<typename obj_type>
class Queue {
	typedef Node<obj_type> sNode;
	typedef Node<obj_type>* pNode;
	size_t size = 0;
	pNode front = nullptr, back = nullptr;
public:
	Queue() = default;
	Queue(const Queue& obj) {
		if (!obj.Empty()) {
			pNode Curr, Next;
			Curr = new sNode(obj.getFront());
			front = Curr;
			Next = obj.front->next;
			while (Next != nullptr) {
				Curr->next = new sNode(Next->data);
				Curr = Curr->next;
				Next = Next->next;
			}
		}
	}
	~Queue() {
		pNode curr = front;
		while (curr != nullptr) {
			pNode next = curr->next;
			delete curr;
			curr = next;
		}
		front = nullptr;
	}
	Queue& operator = (const Queue& obj) {
		if (this != &obj) {
			this->~Queue();
			if (!obj.Empty()) {
				pNode Curr, Next;
				Curr = new sNode(obj.getFront());
				front = Curr;
				Next = obj.front->next;
				while (Next != nullptr) {
					Curr->next = new sNode(Next->data);
					Curr = Curr->next;
					Next = Next->next;
				}
			}
		}
		return *this;
	}
	bool Empty()const {
		return front == nullptr;
	}
	obj_type getFront()const {
		if (!Empty()) {
			return front->data;
		}
		else {
			cout << "Queue is empty" << endl;
			obj_type* ptr = new obj_type;
			obj_type tmp = *ptr;
			delete ptr;
			return tmp;
		}
	}
	obj_type getBack() {
		if (!Empty()) {
			return back->data;
		}
		else {
			cout << "Queue is empty" << endl;
			obj_type* ptr = new obj_type;
			obj_type tmp = *ptr;
			delete ptr;
			return tmp;
		}
	}
	size_t getSize()const {
		return size;
	}
	void push_back(const obj_type& val) {
		size++;
		pNode curr = new sNode(val);
		if (back == nullptr) {
			front = back = curr;
			return;
		}
		back->next = curr;
		back = curr;
	}
	void pop_front() {
		if (Empty()) {
			cout << "Queue is empty" << endl;
			return;
		}
		size--;
		pNode curr = front;
		front = front->next;
		delete curr;
		if (front == nullptr) {
			back = nullptr;
		}
	}
	friend ostream& operator << (ostream& out, const Queue& obj) {
		if (obj.Empty()) {
			out << "Queue is empty" << endl;
		}
		else {
			for (pNode curr = obj.front; curr != nullptr; curr = curr->next) {
				out << curr->data << ' ';
			}
			out << endl;
		}
		return out;
	}
};
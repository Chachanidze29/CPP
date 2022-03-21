#pragma once
#include "Node.h"
class Staque {
	typedef mNode<int> sNode;
	typedef mNode<int>* pNode;
	pNode front = nullptr, back = nullptr;
	size_t Size = 0;
public:
	//Default constructor
	Staque() = default;
	//Copy constructor
	Staque(const Staque& obj) {
		if (!obj.Empty()) {
			pNode curr, prev, next = obj.front;
			front = curr = new (nothrow) sNode(next->data);
			next = next->next;
			prev = curr;
			while (next->next != nullptr) {
				curr = new (nothrow) sNode(next->data, prev);
				prev->next = curr;
				prev = curr;
				next = next->next;
			}
			back = new (nothrow) sNode(next->data, prev);
			prev->next = back;
		}
	}
	//Destructor
	~Staque() {
		pNode current = front;
		while (current != 0) {
			pNode next = current->next;
			delete current;
			current = next;
		}
		front = 0;
	}
	//მინიჭების ოპერატორი
	Staque& operator=(const Staque& obj)
	{
		if (this != &obj) {
			if (!obj.Empty()) {
				pNode curr, prev, next = obj.front;
				front = curr = new (nothrow) sNode(next->data);
				next = next->next;
				prev = curr;
				while (next->next != nullptr) {
					curr = new (nothrow) sNode(next->data, prev);
					prev->next = curr;
					prev = curr;
					next = next->next;
				}
				back = new (nothrow) sNode(next->data, prev);
				prev->next = back;
			}
		}
		return *this;
	}
	//სტაქიუში რიცხვის დამატება
	void Insert(const int& val) {
		pNode ptr = new(nothrow) sNode(val);
		if (ptr == nullptr) {
			cout << "RAM Overflow\n";
			return;
		}
		Size++;
		if (Size == 1) {
			front = back = ptr;
			return;
		}
		//თუ ლუწია ვამატებთ თავში
		if (val % 2 == 0) {
			ptr->next = front;
			front->prev = ptr;
			front = ptr;
		}
		//თუ კენტია ბოლოში
		else {
			ptr->prev = back;
			back->next = ptr;
			back = ptr;
		}
	}
	//ფუნქცია ითვლის ლუწების რაოდენობას
	int countEven() {
		pNode temp = front;
		int even = 0;
		while (temp != nullptr && (temp->data % 2) == 0) {
			even++;
			temp = temp->next;

		}
		return even;
	}
	//ფუნქცია ითვლის კენტების რაოდენობას
	int countOdd() {
		pNode temp = back;
		int odd = 0;
		while (temp != nullptr && (temp->data % 2) == 1) {
			odd++;
			temp = temp->prev;
		}
		return odd;
	}
	void DeleteOdd(const int& num = 1) { //default-ად num არის 1 ანუ თუ არ გადავცემთ პარამეტრს წაშლის 1 კენტ რიცხვს
		if (Size == 0)  // ვამოწმებთ ცარიელია თუ არა სტაქიუ
		{
			cout << "Staque is empty\n";
			return;
		}
		if (num > countOdd() || num < 0) { //ვამოწმებთ გვაქვს თუარა საკმარისი კენტი რიცხვები,ან არის თუარა უარყოფითი
			cout << "We don't have that much odd numbers" << endl;
			return;
		}
		//ვშლით იმდენ კენტ რიცხვს რა მნიშვნელობაც გადმოგვეცა პარამეტრად
		for (int i = 0; i < num; i++) {
			Size--;
			pNode ptr = back;
			back = back->prev;
			delete ptr;
			if (back == nullptr) {
				front = nullptr;
				return;
			}
			back->next = nullptr;
		}
	}
	void DeleteEven(const int& num = 1) { //default-ად num არის 1 ანუ თუ არ გადავცემთ პარამეტრს წაშლის 1 ლუწ რიცხვს
		if (Size == 0) {  // ვამოწმებთ ცარიელია თუ არა სტაქიუ
			cout << "Staque is empty\n";
			return;
		}
		if (num > countEven() || num < 0) { //ვამოწმებთ გვაქვს თუარა საკმარისი ლუწი რიცხვები ან არის თუარა უარყოფითი
			cout << "We don't have that much even numbers" << endl;
			return;
		}
		//ვშლით იმდენ ლუწ რიცხვს რა მნიშვნელობაც გადმოგვეცა პარამეტრად
		for (int i = 0; i < num; i++) {
			Size--;
			pNode ptr = front;
			front = front->next;
			delete ptr;
			if (front == nullptr) {
				back = nullptr;
				return;
			}
			front->prev = nullptr;
		}
	}
	//Delete ფუნქცია რომელიც უკნიდან შლის ელემენტებს
	void Delete(const int& num = 1) { //default-ად num არის 1 ანუ თუ არ გადავცემთ პარამეტრს წაშლის 1 რიცხვს
		if (Size == 0) { //ვამოწმებთ არის თუარა სტაქიუ ცარიელი
			cout << "Staque is empty\n";
			return;
		}
		if (num > Size || num < 0) { //ვამოწმებთ თუ მოცემული რიცხვი არის ჩვენი სტაქიუს ზომაზე მეტი,ან უარყოფითი.თუ ასეა ვწყვტთ მუშაობას
			cout << "We don't have that much numbers" << endl;
			return;
		}
		//ვშლით იმდენ რიცხვს რამდენიც გადმოგვეცა პარამეტრად
		for (int i = 0; i < num; i++) {
			Size--;
			pNode ptr = back;
			back = back->prev;
			delete ptr;
			if (back == nullptr) {
				front = nullptr;
				return;
			}
			back->next = nullptr;
		}
	}
	//ფუნქცია რომელიც ამოწმებს არის თუარა სტაქიუ ცარიელი
	bool Empty()const {
		return front == nullptr;
	}
	//ბეჭდვის ფუნქცია
	friend ostream& operator << (ostream& out, const Staque& obj) {
		if (obj.Empty()) {
			out << "Staque is Empty\n";
		}
		else {
			pNode ptr = obj.front;
			for (ptr; ptr != nullptr; ptr = ptr->next) {
				out << ptr->data << ' ';
			}
			out << endl;
		}
		return out;
	}
};
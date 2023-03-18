#pragma once
#include <iostream>
#include "mNode.h"
using namespace std;
template <typename obj_type = int>
class mQueue {
	 // linked list-ის ტიპის ობიექტისთვის განვსაზღვროთ ალიასი
	 typedef mNode<obj_type>  Node;    // სტანდარტულ შემთხვევაში
	 typedef mNode<obj_type>* pNode;   // პოინტერის შემთხვევაში
	 pNode myFirst, myLast;
public:
	 mQueue() : myFirst(nullptr), myLast(nullptr) {}
	 mQueue(const mQueue& obj) {
		   if (!obj.empty()) {
			    myFirst = myLast = pNode(obj.front());
			    pNode curr = myFirst->next;
			    while (curr->next != nullptr) {
					myLast->next = new Node(curr->data);
					myLast = myLast->next;
					curr = curr->next;
			    }
		   }
		   else {
			    myFirst = nullptr;
			    myLast = nullptr;
		   }

	 }
	 ~mQueue() {
		   pNode first = myFirst, last;
		   do {
			    last = first->next;
			    delete first;
			    first = last;
		   } while (last != nullptr);
	 }
	
	 bool empty() const {
		   return myFirst == nullptr;
	 }

	 void push(const obj_type& value) {
	 	   // შევქმნათ Queue -ში შესატანი მნიშვნელობა
		   pNode newElement = new Node(value);
		   if (empty()) {
		  	    // თუ Queue ცარიელი იყო, მაშინ შექმნილი ობიექტი იქნება
		  	    // მისი პირველი და ბოლო ელემენტი
			    myFirst = myLast = newElement;
		   }
		   else {
		  	    // წინააღმდეგ შემთხვევაში საჭიროა ელემენტის ბოლოში დამატება
			    myLast->next = newElement;
			    myLast = newElement;
		   }

	 }

	 void pop() {
		   if (empty()) {
		  	    // თუ ობიექტი ცარიელია ვერაფერსაც ვერ წავშლით
			    cerr << "Queue is empty!\n";
			    return;
		   }
	 	   // წინააღმდეგ შემთხვევაში წავშალოთ პირველი ობიექტი
 		   pNode ptr = myFirst;
		   myFirst = myFirst->next;
		   delete ptr;
	 	   // თუ Queue -ში მარტო ერთი ობიექტი იყო, მაშინ უნდა
	 	   // შევცვალოთ ბოლო ობიექტის მნიშვნელობაც
		   if (myFirst == nullptr)
			    myLast = nullptr;  
	 }

	 obj_type front() const { 
	 	   if (!empty()) {
			    return myFirst->data;
		   }
		   cout << "Queue is empty!\n";
		   obj_type* ptr = new obj_type;
		   obj_type tmp = *ptr;
		   delete ptr;
		   return tmp;
	 }

	 friend ostream& operator<< (ostream& out, const mQueue& obj) {
		  if (obj.empty()) {
			   out << "\n\tQueue is empty!\n";
		  }
		  else {
			   pNode ptr;
			   for (ptr = obj.myFirst; ptr != nullptr; ptr = ptr->next)
					out << ptr->data << "  ";
		  }
		  out << endl;
		  return out;
	 }
};
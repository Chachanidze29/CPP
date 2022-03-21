#pragma once
// ორადბმული სიის გამოყენებით Deque სტრუქტურის იმპლემენტაცია

#include <iostream>
#include "mNode.h"
using namespace  std;

template <typename obj_type>
class mDeque
{
	 // linked list-ის ტიპის ობიექტისთვის განვსაზღვროთ ალიასი
	 typedef mNode<obj_type>  sNode;   // სტანდარტულ შემთხვევაში
	 typedef mNode<obj_type>* pNode;   // პოინტერის შემთხვევაში
	 pNode front = nullptr, back = nullptr;
	 int Size = 0;
	 obj_type no_value() const 
	 {
		  // თუ ობიექტი არ შეიცავს მნიშვნელობას,
	 	  // მაშინ ფუნქცია აბრუნებს უაზრო მნიშვნელობა
		  obj_type* ptr = new (nothrow) obj_type();
		  obj_type obj = *ptr;
		  delete ptr;
		  return  obj;
	 }
public:
	 mDeque(){}

	 mDeque(const mDeque& obj)
	 {
		  if (!obj.Empty()) {
			   cout << "***************\n";

		  	   // განვსაზღვროთ დამხმარე ცვლადები
			   pNode
		  			_curr,   // მიმდინარე ახალი ობიექტი
		  			_prev,   // ახალი ობიექტისთვის წინა
		  			_next = obj.front;  // obj -ის პირველი ელემენტი

		  	   // შევქმნათ ახალი ობიექტი
			   front = _curr = new (nothrow) sNode(_next->data);
		  	
			   _next = _next->next;  // მითითებელი გადავწიოთ obj -ის შემდეგ ელემენტზე
			   _prev = _curr;        // შევინახოთ _curr -ი წინა ელემენტის როლში
			   while (_next->next != nullptr)
			   {
			   		// შევქმნათ მომდევნო ახალი ობიეტქი, რომელმაც იცის მისი წინა ობიექტი
					_curr = new (nothrow) sNode(_next->data, _prev);
					_prev->next = _curr;   // წინა ობიექტისთვის განვსაზღვროთ მომდევნო
					_prev = _curr;         // წინა ობიექტზე მიმთითებელი გადავიტანოთ მომდევნოზე
					_next = _next->next;   // მითითებელი გადავწიოთ obj -ის შემდეგ ელემენტზე
			   }
		  	   // ციკლი არ ითვალისწინებს ბოლო ელემენტს, ამიტომ ის შევქმნათ დამოუკიდებლად
			   back = new (nothrow) sNode(_next->data, _prev);
			   _prev->next = back;   // წინა ობიექტისთვის განვსაზღვროთ მომდევნო   
		  }
	 }

	 ~mDeque()
	 {
		   pNode ptr;  
		   while (front->next != nullptr)
		   {
				ptr = front;            // შევინახოთ პირველი ობიექტი
				front = front->next;    // მიმთითებელი გადავწიოთ მომდევნოზე
				delete ptr;             // წავშალოთ შენახული ობიექტი
		   }
	 }

	 mDeque& operator=(const mDeque& obj)
	 {
		 if (this != &obj)
		 {
			  if (!obj.Empty()) {
				   // განვსაზღვროთ დამხმარე ცვლადები
				   pNode
						_curr,   // მიმდინარე ახალი ობიექტი
						_prev,   // ახალი ობიექტისთვის წინა
						_next = obj.front;  // obj -ის პირველი ელემენტი

				   // შევქმნათ ახალი ობიექტი
				   front = _curr = new (nothrow) sNode(_next->data);

				   _next = _next->next;  // მითითებელი გადავწიოთ obj -ის შემდეგ ელემენტზე
				   _prev = _curr;        // შევინახოთ _curr -ი წინა ელემენტის როლში
				   while (_next->next != nullptr)
				   {
						// შევქმნათ მომდევნო ახალი ობიეტქი, რომელმაც იცის მისი წინა ობიექტი
						_curr = new (nothrow) sNode(_next->data, _prev);
						_prev->next = _curr;   // წინა ობიექტისთვის განვსაზღვროთ მომდევნო
						_prev = _curr;         // წინა ობიექტზე მიმთითებელი გადავიტანოთ მომდევნოზე
						_next = _next->next;   // მითითებელი გადავწიოთ obj -ის შემდეგ ელემენტზე
				   }
				   // ციკლი არ ითვალისწინებს ბოლო ელემენტს, ამიტომ ის შევქმნათ დამოუკიდებლად
				   back = new (nothrow) sNode(_next->data, _prev);
				   _prev->next = back;   // წინა ობიექტისთვის განვსაზღვროთ მომდევნო   
			  }
		 }
		 return *this;
	 }
	
	 int getSize() const
	 {
		 return Size;   
	 }
	
	 bool Empty() const
	 {
		  return front == nullptr;     // ან   return Size == 0;  
	 }

	 obj_type getFront() const
	 {
		  if (Size != 0)
			   return front->data;
		  return no_value();  // დავაბრუნოთ უაზრო მნიშვნელობა
	 }
	 void pushFront(const obj_type& value)
	 {
	 	  // შევქმნათ ახალი ობიექტი
		  pNode ptr = new (nothrow) sNode(value);

		  // თუ გარკვეული მიზეზით არ მოხდა ობიექტის შექმნა
	 	  if (ptr == nullptr)	
	 	  {
			   cout << "RAM is Full\n";	 	  	
			   return;
	 	  }

		  Size++;   // გავზარდოთ ელემენტების რაოდენობა

		  // თუ სტრუქტურა ცარიელია
	 	  if(front == nullptr)
	 	  {
			 front = back = ptr;
			 return;
	 	  }

	 	  // წინააღმდეგ შეთხვევაში ჩავამატოთ ელემენტი თავში
		  ptr->next = front;
		  front->prev = ptr;
		  front = ptr;
	 }
	
	 void popFront()
	 {
		 if (Size == 0)  // თუ სტრუქტურა ცარიელია
		 {
			 cout << "Deque is empty\n";
			 return;
		 }
	 	 Size--;  // შევამციროთ ელემენტების რაოდენობა
	 	
		 pNode ptr = front;        // შევინახოთ front-ი
		 front = front->next;	   // front-ი გავხადოთ მომდევნო ელემენტი
		 delete ptr;               // წავშალოთ პირველი ელემენტი
		 if (front == nullptr) {   // თუ სტრუქტურაში მხოლოდ ერთი ობიექტია
			  back = nullptr;	   // რადაგანაც მხოლოდ ერთ ელემენტს შეიცავდა 	
		 	  return;
		 }
		 // თუ ერთზე მეტ ელემენტს შეიცავდა front-ს არ ეყოლება წინა ელემენტი
		 front->prev = nullptr;		 
	 }

	 obj_type getBack() const
	 {
		  if (Size != 0)
			   return back->data;
		  return no_value();  // დავაბრუნოთ უაზრო მნიშვნელობა
	 }
	
	 void pushBack(const obj_type& value)
	 {
		  // შევქმნათ ახალი ობიექტი
		  pNode ptr = new (nothrow) sNode(value);

		  // თუ გარკვეული მიზეზით არ მოხდა ობიექტის შექმნა
		  if (ptr == nullptr)
		  {
			   cout << "RAM is Full\n";
			   return;
		  }

		  Size++;   // გავზარდოთ ელემენტების რაოდენობა

		  // თუ სტრუქტურა ცარიელია
		  if (back == nullptr)
		  {
			   front = back = ptr;
			   return;
		  }

		  // წინააღმდეგ შეთხვევაში ჩავამატოთ ელემენტი თავში
		  ptr->prev = back;
		  back->next = ptr;
		  back = ptr;
	 }

	 void popBack()
	 {
		  if (Size == 0)  // თუ სტრუქტურა ცარიელია
		  {
			   cout << "Deque is empty\n";
			   return;
		  }

		  Size--;  // შევამციროთ ელემენტების რაოდენობა

		  pNode ptr = back;        // შევინახოთ front-ი
		  back = back->prev;	   // front-ი გავხადოთ მომდევნო ელემენტი
		  delete ptr;               // წავშალოთ პირველი ელემენტი
		  if (back == nullptr) {   // თუ სტრუქტურაში მხოლოდ ერთი ობიექტია
			   front = nullptr;	   // რადაგანაც მხოლოდ ერთ ელემენტს შეიცავდა 	
			   return;
		  }
		  // თუ ერთზე მეტ ელემენტს შეიცავდა front-ს არ ეყოლება წინა ელემენტი
		  back->next = nullptr;	 	
	 }

	 friend ostream& operator<<(ostream& out, const mDeque& obj)
	 {
		 if (obj.Empty())
		 {
			  out << "Deque is empty\n";
		 }
	 	 else
		 {
			  pNode ptr = obj.front;
			  for (ptr; ptr != nullptr; ptr = ptr->next)
				   cout << ptr->data << " ";
			  cout << endl;
		 }	 	
		 return out;
	 }
};
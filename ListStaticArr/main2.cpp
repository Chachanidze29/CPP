#include <iostream>
#include <cstdlib>
#include <limits>
#include "SList.h"
#include "TList.h"
using namespace std;
double rdouble(int a, int b) {
	// ფუნქცია აგენერირებს და აბრუნებს მითითებულ შუალედიდან
	// შემთხვევით ნამდვილ მნიშვნელობას
	 return a + (double(rand()) / RAND_MAX) * (b - a + 1);
}

int main() {
	 int i;
	 int el_size;
	 cout << "Enter element number in the object: ";
	 cin >> el_size;
		 
	 // გამოვაცხადოთ ობიექტი ელემენტების მითითებული რაოდენობით
	 SList s1(el_size);
	 cout << "\n\n=================================================\n";
	 cout << "The object works similar to the array object.\n";

	 // მოვახდინოთ ობიექტის ელემენტების ინიციალიზირება
 	 for (i = 0; i < el_size; i++)
		  s1[i] = i * i;

	 // ელემენტების ბეჭდვა მასივის მსგავსად
	 for (i = 0; i < el_size; i++)
		  cout << s1[i] << "  ";
	 cout << endl;
	
	 cout << "\n\n=================================================\n";
	 cout << "The object works similar to the ADT object.\n";

	 // გამოვაცხადოთ ცარიელი ობიექტი. ასეთ ობიექტში ელემენტების
	 // ჩამატება შეუძლებელია. ელემენტის ჩამატება იქნება შესაძლებელი
	 // მხოლოდ მას შემდეგ რაც შევცვლით mSize ატრიბუტის
	 // მნიშვნელობას. ასეთი ფუნქცია ხელოვნურადაა შექმნილე 
	 SList s2;

	 // შემდეგი მცდელობა დასრულდება წარუმატებლად 
	 s2.insert(0, 5);
	 cout << s2;

	 cout << "\n\n=================================================\n";
	 // განვსაზღვროთ ობიექტის ახალი ზომა. 
	 cout << "Change the number of elements in the object: ";
	 cin >> el_size; // ამ ზომის მისათითებლად გამოვიყენოთ ცვლადი el_size;
	 s2.resize(el_size);
 	
 	 // მოვახდინოთ s2 ობიექტის შევსება insert ფუნქციის მეშვეობით	
	 for (i = 0; i < el_size; i++)
		  s2.insert(i, i * i);
	 
	 // ელემენტების ბეჭდვა პრიმიტიული ტიპის მსგავსად
	 cout << endl << s2 << endl;

	 // მოვახდინოთ ერთი ობიექტისთვის მეორე ობიექტის მინიჭება და ბეჭდვა
	 s1 = s2;
	 cout << endl << s1 << endl;
	 
	 cout << "\n\n=================================================\n";
	 cout << "After this line code works with template.\n";
	 
	 cout << "\n\n=================================================\n";
	 cout << "\n\tWorking with integer values.\n";
	 cout << "Enter number of elements in the object: ";
	 cin >> el_size;
	 // შევქმნათ განზოგადებული ტიპის ობიექტი double ტიპის მონაცემებისთვის */
	 TList<int> t1(el_size);
	 
	 // შევავსოთ ობიექტი შემთხვევითი პრინციპით მიღებული მთელი
	 // მნიშვნელობებით შუალედიდან [10, 500]
	 for (i = 0; i < el_size; i++) {
		 t1.insert(i, rand()% 490 + 10);
	 }
	 cout << endl << t1 << endl;

	 int rem_number; // ცვლადი ამოსაშლელი ელემენტების რაოდენობის მისათითებლად
	 int rem_at;     // ცვლადი ამოსაშლელი ელემენტის ინდექსის მნიშვნელობის მისათითებლად
	  
	 // განვსაზღვროთ ამოსაშლელი ელემენტების რაოდენობა
	 rem_number = rand() % el_size;
	 for (i = 0; i < rem_number; i++)
	 {
		 el_size--;
		 // განვსაზღვროთ ამოსაშლელი ელემენტების ინდექსი
		 rem_at = rand() % el_size;
		 cout << "Element removed at index: " << rem_at << endl;
		 t1.eraze(rem_at);	 	
	 }
	 cout << t1 << endl;
	
	 cout << "\n\n=================================================\n";
	 cout << "\n\tWorking with double values.\n";
	 cout << "Enter number of elements in the object: ";
	 cin >> el_size;
	 // შევქმნათ განზოგადებული ტიპის ობიექტი double ტიპის მონაცემებისთვის
	 TList<double> t2(el_size);

	 // შევავსოთ ობიექტი შემთხვევითი პრინციპით მიღებული ნამდვილი
	 // მნიშვნელობებით შუალედიდან [10, 500]
	 for (i = 0; i < el_size; i++) {
		  t2.insert(i, rdouble(10, 500));
	 }
	 cout << endl << t2 << endl;

	 // განვსაზღვროთ ამოსაშლელი ელემენტების რაოდენობა
	 rem_number = rand() % el_size;

	 for (i = 0; i < rem_number; i++)
	 {
		  el_size--;
		  // განვსაზღვროთ ამოსაშლელი ელემენტების ინდექსი
		  rem_at = rand() % el_size;
		  cout << "Element removed at index: " << rem_at << endl;
		  t2.eraze(rem_at);
	 }
	 cout << t2 << endl; /**/
	return 0;
}

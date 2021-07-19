#include <ctime>
#include <vector>
#include "SList.h"
// N -ის გაზრდით იზრდება განსხვავება
const int N = 10000000;

void main() {
	 // დინამიური სტრუქტურის ფუნქციონალის შემოწმება
	 SList* obj1 = new SList(20);
	 for (int i = 0; i < 10; i++) {
		  // სტრუქტურაში ელემენტის ჩამატება (insert)
		  obj1->insert(i * i, i);
	 }
	 cout << *obj1 << "\n\n";

	 // სტრუქტურიდან წავშალოთ ელემენტი (eraze)
	 obj1->eraze(8);
	 obj1->eraze(4);
	 cout << *obj1 << "\n\n";

	 
	 SList* obj2 = new SList(15);
	 for (int i = 0; i < 5; i++) {
		  obj2->insert(i * i * i, i);
	 }
	 cout << *obj2 << "\n\n";

	 // მინიჭება
	 obj1 = obj2;

	 cout << *obj1 << "\n\n";
	 cout << *obj2 << "\n\n\n";


	 // დინამიური სტრუქტურის შედარება ვექტორთან
	 auto t = time(NULL);
	 SList* obj3 = new SList(N);
	 for (int i = 0; i < N; i++) {
		  obj3->insert((i * i) % 100, i);
	 }
	 cout << "xdeba simravlis shevseba " << N << " elementit.\n";
	 cout << "shesabamisi simravlis shevsebas moxda:\n";
	 cout << "\n\tdinamiuri obieqti: " << time(NULL) - t << " wamshi." << endl;

	 t = time(NULL);
	 vector<int>* obj4 = new vector<int>();
	 for (int i = 0; i < N; i++) {
		  obj4->push_back((i * i) % 100);
	 }
	 cout << "\n\tveqtori          : " << time(NULL) - t << " wamshi." << endl;
}
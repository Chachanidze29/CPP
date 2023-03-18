#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;
class HTable {
	 static const int h_size = 10;

	 // list ობიექტი მონაცემების შესანახად
	 list< pair<int, string> > htab[h_size];

	 int hFunc(int k) const {
		  return k % h_size;
	 }
public:

	 HTable() = default;

	 bool isEmpty() const {
		  // ფუნქცია ამოწმებს htab -ი არის თუ არა ცარიელი
		  for (auto& ob : htab)
			   // htab -ის ყოველი ობიექტი თვითონ შეიძლება 
			   // წარმოადგენდეს სიმრავლე
			   if (ob.size() > 0)
					return false;
		  return true;
	 }

	 void insert(int key, string value) {
		  // ფუნქცია ახდენს htab -ის შევსებას ელემენტებით

		  // ჰეშ ფუნქციის გამოყენებით დავაგენერიროთ შესაბამისი ინდექსი
		  int index = hFunc(key);

		  // შევინახოთ იტერატორი შესაბამის ელემენტზე
		  auto& curr = htab[index];

		  // თუ მიმდინარე ინდექსზე უკვე იყო ელემენტები განთავსებული
		  if (curr.size() > 0) {
			   for (auto it = begin(curr); it != end(curr); it++) {
					// მოვძებნოთ მსგავსი გასაღები თუ იყო გამოყენებული
					if (it->first == key) {
						 // თუ გასაღები უკვე იყო გამოყენებულია
						 if (it->second == value)
							  // და გამოყენებული იყო მნიშვნელობაც
							  cout << "\n\tSuch value (" << value << ") was used previously !!!\n";
						 else {
							  string curr_val = it->second;
							  // თუ მნიშნელობა არ ყოფილა გამოყენებული
							  it->second = value;  // შევცვალოთ ძველი ახლით
							  cout << "\n\tCurrent value (" << curr_val << ") was replaced with " << value << " !!!\n";
						 }
						 return;
					}
			   }
		  }
		  // მიმდინარე ინდექსზე ბოლოში ჩავამატოთ ახალი მნიშვნელობა
		  curr.emplace_back(key, value);
		  // curr.push_back(pair<int, string> (key, value)); 
	 }

	 void remove(int key) {
		  // ფუნქცია ახდენს htab -იდან ელემენტის წაშლას

		  // ჰეშ ფუნქციის გამოყენებით დავაგენერიროთ შესაბამისი ინდექსი 
		  int index = hFunc(key);

		  // თუ მითითებულ ინდექსზე მნიშვნელობები არაა განთავსებული
		  if (htab[index].size() == 0) {
			   cout << "\n\t!!! The set under current key (" << key << ") is empty. !!!\n";
			   return;
		  }

		  // შევინახოთ იტერატორი შესაბამის ელემენტზე
		  auto& curr = htab[index];

		  // შესაბამის სიმრავლეზე მოვძებნოთ იყო თუ არა გასაღები გამოყენებული
		  for (auto it = begin(curr); it != end(curr); it++) {
			   // თუ გასაღები იყო გამოყენებული
			   if (it->first == key) {
					// წავშალოთ მიმდინარე ელემენტი
					it = curr.erase(it);
					cout << "\n\t!!! Current element (" << key << ") was removed !!!\n";
					return;
			   }
		  }
		  cout << "\n\t!!! Such key (" << key << ") does not exist. !!!\n";
	 }

	 string search(int key) const {
		  // ფუნქცია ეძებს და აბრუნებს კონკრეტულ გასაღებზე განთავსებულ მნიშვნელობას

		  // ჰეშ ფუნქციის გამოყენებით დავაგენერიროთ შესაბამისი ინდექსი 
		  int index = hFunc(key);

		  // თუ მითითებულ ინდექსზე მნიშვნელობები არაა განთავსებული
		  if (htab[index].size() == 0)
			   return "\n\t!!! The set under current key is empty !!!\n";

		  // შევინახოთ იტერატორი შესაბამის ელემენტზე
		  auto& curr = htab[index];

		  // შესაბამის სიმრავლეზე მოვძებნოთ იყო თუ არა გასაღები გამოყენებული
		  for (auto it = begin(curr); it != end(curr); it++) {
			   // თუ გასაღები იყო გამოყენებული
			   if (it->first == key)
					return "\tvalue: " + it->second + "\n";
		  }

		  // თუ გასაღები არ ყოფილა გამოყენებული
		  return "\n\t!!! Such key does not exist. !!!\n";
	 }

	 friend ostream& operator<<(ostream& out, const HTable& obj) {
		  if (obj.isEmpty()) {
			   // თუ ჰეშ ცხრილი ცარიელია დავბეჭდოთ შესაბამისი შეტყობინება
			   out << "\n\t!!! Current Hash Table is empty !!!\n";
		  }
		  else {
			   // წინააღმდეგ შემთხვევაში დავბეჭდოთ ცალკე ინდექსი
			   // და ინდექსზე გამოყენებული წყვილები (key, value)
			   for (int i = 0; i < h_size; i++) {
					out << "Index: [" << i << "]";
					if (obj.htab[i].size() == 0)
						 out << "\n\tSet under current index is empty.\n\n";
					else {
						 out << "\n\tkey:\tvalue: ";
						 for (auto it = obj.htab[i].begin(); it != obj.htab[i].end(); it++)
							  out << "\n\t " << it->first << "\t  " << it->second;
						 out << endl << endl;
					}
			   }
		  }
		  out << endl;
		  return out;
	 }
};

int nGen(int a = 1, int b = 100) {
	 return rand() % (b - a + 1) + a;
}

int main() {
	 srand(time(NULL));

	 HTable ht;
	 cout << ht << endl;

	 cout << "\n\n\n\n1. ------- function: insert -------\n";

	 // შევავსოთ ჰეშ ცხრილი ელემენტების გარკვეული რაოდენობით
	 int i, key, N; 
		  N = nGen(20, 60);
	 for (i = 0; i < N; i++) {
		  key = nGen();
		  // ვინახავთ მთელ მნიშვნელობას და მის სტრიქონულ წარმოდგენას
		  ht.insert(key, to_string(key));
	 }
	 cout << ht << endl;

	 cout << "\n\n\n\n2. ------- function: remove -------\n";
	 // სიმრავლიდან წავშალოთ მნიშვნელობათა გარკვეული რაოდენობა
	 N = nGen(2, 8);
	 for (i = 0; i < N; i++) {
		  key = nGen();
		  ht.remove(key);
	 }

	 cout << "\n\n\n\n3. ------- function: search -------\n";
	 // სიმრავლეში მოვძებნოთ გარკვეულ გასაღებებზე განთავსებული მნიშვნელობები
	 N = nGen(2, 10);
	 for (i = 0; i < N; i++) {
		  key = nGen();
		  cout << "key: " << key << "\t" << ht.search(key) << endl;
	 }

	 /*ht.insert(50, "50");
	 ht.insert(50, "50");
	 ht.insert(50, "150");*/

	 return 0;
}
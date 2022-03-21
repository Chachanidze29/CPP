// დავალება 1
#include <iostream>
#include <array>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
//class Test {
//private:
//	int m;
//	static int a;
//public:
//	Test() = default;
//	Test(int);
//	~Test();
//	static int getA();
//	int getM()const;
//	void info();
//};
//int Test::a = 0;
//Test::Test(int n) : m(n) { a++; }
//Test::~Test() { --a; }
//int Test::getA() { return a; }
//int Test::getM()const {
//	return m;
//}
//void Test::info() {
//	cout << m++ << ' ' << ++a << endl;
//}
//int main()
//{
//	cout << Test::getA() << endl;
//	Test* obj = new Test;
//	obj->info();
//	delete obj;
//	Test obj1{ 19 };
//	cout << 20 + obj1.getM() << endl
//		<< ' ' << obj1.getA() << endl;
//	//cout << Test::getA() << endl; დაბეჭდავს 0ს რადგან არცერთი ობიექტი არ გვაქვს შექმნილი და თავდაპირველად a არის 0
//	//obj->info() დაბეჭდავს პირველ მონაცემს,ანუ m-ს, ნაგავს რადგან არ ვაწვდით მას ხოლო a იქნება 1 იმიტომ რომ ჩვენ ვზრდით a-ს ობიექტის შექმნისას
//	//cout << 20 + obj1.getM() << endl<< ' ' << obj1.getA() << endl; ეს დაბეჭდავს 39-ს და 1-ს რადგანაც ჩვენ m პარამეტრად გადავეცით 19
//	//და შემდეგ მივუმატეთ ოცი და დავბეჭდეთ,ხოლო a იქნება 1 რადგანაც ჩვენ პირველად შექმნილი ობიექტი გავანადგურეთ და ამიტომაც a გახდა 0
//	//ხოლო ახალი ობიექტის შექმნისას a კვლავ გაიზარდა და გახდა 1
//}

//დავალება 2

//const int N = 5; //რაოდენობა პირობაში არ იყო მითითებული ამიტომაც ჩემით ავიღე 5
//class Sportsmen {
//	string name, last_name;
//	int prizes, age;
//public:
//	Sportsmen() = default;
//	int getAge()const {
//		return age;
//	}
//	int getPrizes()const {
//		return prizes;
//	}
//	void fill(istream& in) {
//		in >> name >> last_name >> prizes >> age;
//	}
//	void fout(ostream& out) {
//		out << name << ' ' << last_name << ' ' << prizes << ' ' << age << endl;
//	}
//};
//void fillArr(array<Sportsmen, N>&arr) {
//	ifstream ifs("Sportsmen.txt");
//	for (int i = 0; i < N; i++) {
//		arr[i].fill(ifs);
//	}
//}
//void printYoungest(array<Sportsmen, N>&arr) {
//	ofstream ofs("Young.txt");
//	Sportsmen* min = &arr[0];
//	for (int i = 1; i < N; i++) {
//		if (min->getAge() > arr[i].getAge())
//			min = &arr[i];
//	}
//	ofs << "Youngest Sportsmen's info ";
//	for (int i = 0; i < N; i++) {
//		if (min->getAge() == arr[i].getAge())
//			arr[i].fout(ofs);
//	}
//}
//bool interval(const Sportsmen& s) {
//	return s.getPrizes() >= 15 && s.getPrizes() <= 20;
//}
//void countPrizes(const array<Sportsmen, N>&arr) {
//	ofstream ofs("Bravo.txt");
//	int count = count_if(arr.begin(), arr.end(), interval);
//	ofs << "Number of Sportsmen with prizes in interval [15,20] ";
//	ofs << count;
//}
//int main() {
//	array<Sportsmen, N>arr;
//	fillArr(arr);
//	printYoungest(arr);	
//	countPrizes(arr);
//}

//დავალება 3
//void changeMat(double** mat, const int& N, const int& K, const int& m) {
//	int min_index = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < K; j++) {
//			if (mat[i][min_index] > mat[i][j])
//				min_index = j;
//		}
//		if (min_index <= K - 3) {
//			mat[i][min_index] = mat[i][min_index + 1] + mat[i][min_index + 2];
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < K; j++)
//			if (i == m) {
//				mat[i][j] /= 2.5;
//			}
//	}
//}
//void fillMat(double** mat, const int& N, const int& K) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < K; j++) {
//			cin >> *(*(mat + i) + j);
//		}
//	}
//}
//void printMat(double** mat, const int& N, const int& K) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < K; j++) {
//			cout << *(*(mat + i) + j) << ' ';
//		}
//		cout << endl;
//	}
//}
//int main() {
//	int N, K, m;
//	cout << "Enter size of matrix : ";
//	cin >> N >> K;
//	double** mat = new(nothrow)double* [N];
//	for (int i = 0; i < N; i++) {
//		mat[i] = new(nothrow)double[K];
//	}
//	fillMat(mat,N,K);
//	printMat(mat, N, K);
//	cin >> m;
//	changeMat(mat, N, K, m);
//	printMat(mat, N, K);
//	for (int i = 0; i < N; i++) {
//		delete[]mat[i];
//	}
//	delete[]mat;
//	mat = nullptr;
//}

//დავალება 4
//class Sea {
//	string name;
//	int depth;
//public:
//	Sea(istream& in = cin) {
//		string line, word;
//		getline(cin, line);
//		istringstream sin(line);
//		while (sin >> word && word[0] < '0' || word[0]>'9') {
//			name += ' ' + word;
//		}
//		depth = stoi(word);
//	}
//	void printInfo()const {
//		cout << "Sea's name " << name << " It's depth " << depth << endl;
//	}
//	friend bool compare(const Sea& s1,const Sea& s2) {
//		return s1.depth > s2.depth;
//	}
//};
//void printAscending(const Sea* s1, const Sea* s2, const Sea* s3) {
//	if (compare(*s1, *s2))
//		swap(s1, s2);
//	if (compare(*s2, *s3))
//		swap(s2, s3);
//	if (compare(*s1, *s2))
//		swap(s1, s2);
//	s1->printInfo(); s2->printInfo(); s3->printInfo();
//}
//
//int main() {
//	Sea s1, s2, s3;
//	printAscending(&s1, &s2, &s3);
//}
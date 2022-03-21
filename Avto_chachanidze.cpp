#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
using namespace std;

//დავალება 1

/*double calculation(double& x);

int main() {
	double num;
	cout << "shemoitanet namdvili ricxvi ";
	cin >> num;
	cout << "funqciis mushaobis shedegi aris " << calculation(num) << endl;
}

double calculation(double& x) {
	if (x >= -7.5 && x < 15)
		return 2 * x * x * x + 42 * x - 35;
	return 76 - 12 * x - 38 * x * x;
}*/

//დავალება 2

/*bool predicat(int& N);

int main() {
	vector<int> vec;
	default_random_engine dre;
	uniform_real_distribution<double> rdis(10, 40);
	for (int i = 0; i < 500; i++) {
		vec.push_back(rdis(dre));
	}
	int count=count_if(vec.begin(), vec.end(), predicat);
	cout << count << endl;
}

bool predicat(int& N) {
	return (N != 21 && N != 32);
}*/

/*int main() {
	vector<int> vec;
	default_random_engine dre;
	uniform_real_distribution<double> rdis(10, 40);
	for (int i = 0; i < 500; i++) {
		vec.push_back(rdis(dre));
		
	}
	auto lambda = [](int i) {return i != 21 && i != 32; };
	int count = count_if(vec.begin(), vec.end(), lambda);
	cout << count << endl;
}*/

//დავალება 3

void fillvec(vector<char>&);
bool predicat(char);
int main() {
	vector<char>vec;
	fillvec(vec);
	for (size_t i = 0; i < vec.size(); i++) {
		cout << vec[i] << ' ';
		if ((i) % 8 == 7)
			cout << endl;
	}
	cout << endl;
	int max = -1;
	for (int i = 0; i < vec.size(); i++) {
		if (predicat(vec[i])) {
			if (max == -1)
				max = i;
			if (vec[max] < vec[i])
				max = i;
		}
	}
	if (max == -1)
		cout << "veqtorshi [32, 100]  intervalshi motavsebuli arcerti elementi ar aris" << endl;
	else 
		cout <<"veqtorshi [32, 100]  intervalshi motavsebuli udidesi elementi aris " <<vec[max] << " xolo misi indeqsi = " << max << endl;
}

void fillvec(vector<char>&vec) {
	char ch;
	ifstream ifs("simbolo.txt");
	while (ifs >> ch)
		vec.push_back(ch);
}

bool predicat(char ch) {
	return (int(ch) >= 32 && int(ch) <= 100);
}


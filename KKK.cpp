#include<iostream>
#include<fstream>
#include<vector>
#include <string>

using namespace std;

void printvector(vector<string>s);

bool lenght(string w);

int main() {
	vector<string> words;
	string name;
	ifstream ifs("words.txt");
	while (ifs >> name) {
		words.push_back(name);
	}
	printvector(words);
	cout << endl;
	for (int i = 0; i < words.size(); i++) {
		if (lenght(words[i])) cout << words[i] << " aris xut asoze metiani sityva" << endl;
	}
	for (int i = 0; i < words.size(); i++) {
		if (lenght(words[i])) {
			words.erase(words.begin() + i);
			i--;
		}
	}
	cout << endl;
	printvector(words);
}

bool lenght(string w) {
		return w.size() > 5;
}

void printvector(vector<string>s) {
	for (auto m : s)
		cout << m << endl;
}



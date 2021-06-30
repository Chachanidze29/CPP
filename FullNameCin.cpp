#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Cat {
	string nickname, color;
	int weight;
public:
	Cat(ifstream&);
	void showdata();
};
Cat::Cat(ifstream& ifs) {
	string line, word;
	getline(ifs, line);
	istringstream sin(line);
	while (sin >> word && word[0] < '0' || word[0]>'9') {
		nickname += ' ' + word;
	}
	weight = stoi(word);
	sin >> color;
}
void Cat::showdata() {
	ofstream ofs("out.txt", ios::app);
	ofs << "Cat's nickname " << nickname << " It's weight " << weight << " It's color " << color << endl;
}
int main() {
	ifstream ifs("Cats.txt");
	Cat c1(ifs);
	c1.showdata();
}
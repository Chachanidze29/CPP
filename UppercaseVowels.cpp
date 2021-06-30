#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string name, newname="";
	int i=0;
	cin >> name;
	while (i < name.size()) {
		switch (name[i]) {
		case 'a': 
		case 'e':
		case'i':
		case'o':
		case'u': newname += name[i] - 32; break;   //newname=newname+(name[i]-32);---არ მუშაობს
		default: newname += name[i]; break;
		}
		i++;
	}
	cout << "newname=" << newname << endl;
	


}

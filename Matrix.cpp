#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
const int V = 5;
//a b c d f
//0 1 2 3 4
int main() {
	int g[V][V];
	ifstream ifs("Data.txt");
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++) {
			int a;
			ifs >> a;
			g[i][j] = a;
		}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << setw(4) << g[i][j];
		cout << endl;
	}
}

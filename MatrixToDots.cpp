#include <iostream>
#include <fstream>

using namespace std;
const int N = 6;

int main() {
	int matrix[N][N];
	int num;
	fstream ifs("matrix.txt");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			ifs >> matrix[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 1)
				cout << "(v" << i + 1 << ";v" << j + 1 << ")";
		}
		cout << endl;
	}
}




#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
const int N = 6;
void outputMatrix(const int a[N][N]);
int main() {
	int matrix[N][N];
	int num;
	fstream ifs("matrix.txt");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			ifs >> matrix[i][j];
	}
	for (int i = 0; i < N; i++) {
		int counter = 0;
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 1)
				counter++;
		}
		cout <<"V["<<i+1<<"]" <<"hyavs "<< counter<<" mezobeli" << endl;
	}
}


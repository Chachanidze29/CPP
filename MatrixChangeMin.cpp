#include  <iostream>
#include <fstream>
using namespace std;
void print(int** mat, int R, int C) {
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << mat[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}
void Change(int** mat, int R, int C) {
	int min_ind = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mat[i][j] < mat[i][min_ind])
				min_ind = j;
		}
		if (min_ind >= 2)
			mat[i][min_ind] = mat[i][min_ind-2] + mat[i][min_ind-1];
	}
}

int main()
{
	srand(time(NULL));
	int R, C;
	cout << "ShemoitaneT matricis ganzomilebebi N da M:  ";
	cin >> R >> C;
	int** mat = new (nothrow) int* [R];
	for (int i{}; i < R; i++)
		mat[i] = new (nothrow) int[C];
	ifstream ifs("Matrix.txt");
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ifs >> mat[i][j];
		}
	}
	print(mat, R, C);
	Change(mat, R, C);
	print(mat, R, C);
	for (int i{}; i < R; i++)
		delete[] mat[i];
	delete[] mat;
	mat = nullptr;
}

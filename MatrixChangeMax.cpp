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
void Change (int** mat, int R, int C) {
	int max_ind = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mat[i][j] > mat[i][max_ind])
				max_ind = j;
		}
		if (max_ind < R - 2)
			mat[i][max_ind] = mat[i][max_ind + 1] + mat[i][max_ind + 2];
	}
}

int main()
{
	srand(time(NULL));
	int R, C;
	cout << "ShemoitaneT matricis ganzomilebebi R da C:  ";
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

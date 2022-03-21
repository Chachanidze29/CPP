#include <iostream>
using namespace std;
constexpr auto vNum = 4;
void printMatrix(int matrix[][vNum]);
void TransitiveClosure(int graph[][vNum]) {
	int matrix[vNum][vNum];
	for (int i = 0; i < vNum; i++) {
		for (int j = 0; j < vNum; j++) {
			matrix[i][j] = graph[i][j];
		}
	}
	for (int k = 0; k < vNum; k++) {
		for (int i = 0; i < vNum; i++) {
			for (int j = 0; j < vNum; j++) {
				matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
			}
		}
	}
	printMatrix(matrix);
}
void printMatrix(int matrix[][vNum]) {
	for (int i = 0; i < vNum; i++) {
		for (int j = 0; j < vNum; j++) {
			if (i == j)
				cout << "1 ";
			else
				cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}
int main() {
	int graph[vNum][vNum] = { {1, 1, 0, 1},
					   {0, 1, 1, 0},
					   {0, 0, 1, 1},
					   {0, 0, 0, 1}
	};
	TransitiveClosure(graph);
}
#include <iostream>
using namespace std;
#define vNum 5
#define INF 999
void printMatrix(int matrix[][vNum]);
void floydWarshell(int graph[][vNum]) {
	int matrix[vNum][vNum];
	bool negativeCycle = false;
	int i, j, k;
	for (i = 0; i < vNum; i++) {
		for (j = 0; j < vNum; j++) {
			matrix[i][j] = graph[i][j];
		}
	}
	for (k = 0; k < vNum; k++) {
		for (i = 0; i < vNum; i++) {
			for (j = 0; j < vNum; j++) {
				if (matrix[i][k] + matrix[k][j] < matrix[i][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
			}
		}
	}
	for (int i = 0; i < vNum; i++) {
		for (int j = 0; j < vNum; j++) {
			if (i == j && matrix[i][j] != 0)
				negativeCycle = true;
		}
	}
	if (negativeCycle)
		cout << "Graph contains negative cycle" << endl;
	else
		printMatrix(matrix);
}
void printMatrix(int matrix[][vNum]) {
	for (int i = 0; i < vNum; i++) {
		for (int j = 0; j < vNum; j++) {
			if (matrix[i][j] == INF)
				cout << "INF ";
			else
				cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}
int main() {
	int graph[vNum][vNum] = { {0, 15, INF, INF,INF },
			 {INF, 0, 8, 1,-22},
			 {INF, INF, 0, INF,INF},
			 {INF, INF, 4, 0,2},
			 {1, INF, INF, INF,0} };
	floydWarshell(graph);
}
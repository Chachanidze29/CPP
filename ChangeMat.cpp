#include <iostream>
using namespace std;
void fillMat(int** Mat, const int& M, const int& N) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> *(*(Mat + i) + j);
		}
	}
}
void printMat(int** Mat, const int& M, const int& N) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << *(*(Mat + i) + j) << ' ';
		}
		cout << endl;
	}
}
void changeMat(int** Mat, const int& M, const int& N) {
	int max_index = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (Mat[i][max_index] < Mat[i][j])
				max_index = j;
		}
		swap(Mat[i][max_index], Mat[i][N - 2]);
	}
}
int main() {
	int M = 4, N = 3;
	int** Mat = new(nothrow)int*[M];
	for (int i = 0; i < M; i++) {
		Mat[i] = new(nothrow)int[N];
	}
	fillMat(Mat, M, N);
	cout << endl;
	changeMat(Mat, M, N);
	printMat(Mat, M, N);
}
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

// იპოვე ყველაზე ხშირად გამეორებული

int findLargest(vector<int>& vec) {
	set<int> D;
	int ans = -1;
	for (int i = 0; i < vec.size(); ++i) {
		if (D.count(vec[i]))
			ans = max(ans, vec[i]);
		else
			D.insert(vec[i]);
	}
	return ans;
}

//

int maxSignals(const string& T, const int MD) {
	int i, N = T.size(), P = 0, M = 0, K, j;
	K = 2 * MD + 1;
	if (K > N) K = N;
	for (i = 0; i < K; i++) {
		M += T[i] == 'X';
	}
	cout << M << endl << i << endl;
	for (P = M, j = 1; i < N; ++i, ++j, P = max(P, M)) {
		M += (T[i] == 'X') - (T[j] - 1 == 'X');
	}
	return P;
}

//

string areSimilar(const string& code1, const string& code2) {

}

int main() {
	vector<int> vec{ 1,2,3,4,5 };
	cout << maxSignals("..X.X.X..",2) << endl;
	int num = 20;
	string str = to_string(num);
}
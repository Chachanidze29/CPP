#include <iostream>

using namespace std;

int main() {
	const int n = 12;
	int x[n] = { 1,2,2,3,3,3,8,5,1,1,2,7}, p[n] = { 0 }, gan = 0, h, sul = 0, j;
	h = 0;
	do {
		p[h] = 1, gan++, sul++;
		for (j = h + 1; j < n; j++) 
			if (x[j] == x[h]) {
				p[j] = 1; sul++;
			}
		j = h; while (p[j])j++;
		h = j;	
	}
	while (sul != n);
	cout << "gansxvavebulia " << gan << " cali \n";
}





























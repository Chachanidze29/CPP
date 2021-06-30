#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

void mysort(vector<int>&,vector<int>&);
void fillvector(vector<int>&);
void printvector(vector<int>&);

int main() {
    vector<int>vec;
    vector<int>newvec;
    clock_t tstart = clock();
    fillvector(vec);
    mysort(vec,newvec);
    printvector(newvec);
    printf("time taken: %.2fs\n ", (double)(clock() - tstart) / CLOCKS_PER_SEC);
}
void fillvector(vector<int>&vec) {
    for(double i=0;i<10000.;i++)
        vec.push_back(rand());

}
void printvector(vector<int>&vec) {
    for (auto m : vec)
        cout << m << ' ';
    cout << endl;
}
void mysort(vector<int>& vec, vector<int>& newvec) {
    while (vec.size() != 0) {
        int min_index = 0;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] < vec[min_index])
                min_index = i;
        }
        newvec.push_back(vec[min_index]);
        vec.erase(vec.begin() + min_index);
    }
}

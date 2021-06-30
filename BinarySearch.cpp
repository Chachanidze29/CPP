#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
int binarySearch(vector<int>&, const int&);
void mysort(vector<int>&, vector<int>&);
void fillvector(vector<int>&);
void printvector(vector<int>&);

int main() {
    vector<int>vec;
    vector<int>newvec;
    fillvector(vec);
    mysort(vec, newvec);
    int m;
    cout << "shemoitanet ricxvi romelic gsurt rom vipovot : ";
    cin >> m;
    int ind = binarySearch(newvec, m);
    cout << ind << endl;
    printvector(newvec);
}
int binarySearch(vector<int>& vec, const int& value) {
    int start = 0;
    int end = vec.size() - 1;
    for (int i = 0; i < vec.size(); i++) {
        int middle = (end - start) / 2;
        if (vec[i] == value) {
            return i;
        }
        else if (vec[middle] > value) {
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }
    }
    return -1;
}
void fillvector(vector<int>& vec) {
    srand(time(NULL));
    for (double i = 0; i < 10000.; i++)
        vec.push_back(rand());

}
void printvector(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (i % 10 == 0)
            cout << endl;
        cout << vec[i] << ' ';
    }
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

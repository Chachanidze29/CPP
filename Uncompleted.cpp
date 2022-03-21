#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void mysort(vector<int>& vec, vector<int>& newvec);
void fillvector(vector<int>& vec);
void printvector(const vector<int>& vec);
void frequency(vector<int>& vec);

int main() {
    vector<int> vec;
    vector<int>newvec;
    fillvector(vec);
    mysort(vec,newvec);
    frequency(newvec);
}
void fillvector(vector<int>& vec) {
    ifstream ifs("ints.txt");
    int num;
    while (ifs >> num)
        vec.push_back(num);
}
void printvector(const vector<int>& vec) {
    for (auto m : vec)
        cout << m <<' ';
    cout << endl;
}
void frequency(vector<int>& vec) {
    int counter = 1;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == vec[i+1])
            counter++;
        else {
            cout << vec[i] << ' ' << counter << endl;
            counter = 1;
        }
    }
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





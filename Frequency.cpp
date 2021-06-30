#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void mysort(vector<int>&, vector<int>&);
void fillvector(vector<int>&);
void printvector(const vector<int>&);
void get_unique(vector<int>&, vector<int>&);
void frequent(vector<int>&, vector<int>&);

int main() {
    vector<int> vec;
    vector<int> newvec;
    fillvector(vec);
    mysort(vec, newvec);
    get_unique(newvec, vec);
    cout << "Chveni veqtori aris : ";
    printvector(newvec);
    frequent(newvec, vec);
}
void fillvector(vector<int>& vec) {
    ifstream ifs("ints.txt");
    int num;
    while (ifs >> num)
        vec.push_back(num);
}
void printvector(const vector<int>& vec) {
    for (auto m : vec)
        cout << m << ' ';
    cout << endl;
}
void get_unique(vector<int>& newvec, vector<int>& vec) {
    vec.push_back(newvec[0]);
    for (int i = 1; i < newvec.size(); i++) {
        if (newvec[i] != newvec[i - 1])
            vec.push_back(newvec[i]);
    }
}
void frequent(vector<int>& newvec, vector<int>& uniquevec) {
    int counter = 0;
    for (int i = 0; i < uniquevec.size(); i++) {
        counter = 0;
        for (int n = 0; n < newvec.size(); n++) {
            if (uniquevec[i] == newvec[n]) {
                counter++;
            }
        }
        cout << "Ricxvi " << uniquevec[i] << " veqtorshi gvxvdeba " << counter << " jer" << ' ';
        cout << endl;
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





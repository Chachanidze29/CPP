#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void fillvector(vector<int>&);
void swap(int* xp, int* yp);
void selectionSort(vector<int>&);
void printvector(vector<int>&);
pair<size_t, size_t>most_frequent(const vector<int>&);
int main() {
    vector<int>vec;
    fillvector(vec);
    selectionSort(vec);
    cout << "chveni veqtori aris : ";
    printvector(vec);
    pair<size_t, size_t> max = most_frequent(vec);
    cout << "masshi yvelze xshirad gvxvdeba elementi : " << vec[max.first] <<
        "\nigi shegxvda sul : " << max.second << " jer" << endl;
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(vector<int>&vec)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray 
    for (i = 0; i < vec.size() - 1; i++)
    {
        // Find the minimum element in unsorted array 
        min_idx = i;
        for (j = i + 1; j < vec.size(); j++)
            if (vec[j] < vec[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element 
        swap(&vec[min_idx], &vec[i]);
    }
}
void fillvector(vector<int>&vec) {
    int num;
    ifstream ifs("ints.txt");
    while (ifs >> num)
        vec.push_back(num);
}
void printvector(vector<int>&vec) {
    for (auto m : vec)
        cout << m << '\t';
    cout << endl;
}
pair<size_t, size_t>most_frequent(const vector<int>&vec) {
    pair<size_t, size_t> max;
    max.first = 0; max.second = 1;
    size_t counter{ 1 };
    for (size_t i{}; i < vec.size() - 1; i++)
        if (vec[i] == vec[i + 1])
            counter++;
        else if (counter > max.second) {
            max.second = counter;
            max.first = i;
            counter = 1;
        }
        else counter = 1;
    return max;
}
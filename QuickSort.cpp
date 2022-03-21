#include <iostream>
#include<algorithm>
#include <chrono>

using namespace std;

#define N 1000000

auto get_time() { return std::chrono::high_resolution_clock::now(); }

void quickSort(int* array, int from, int to)
{
    if (from >= to)
        return;
    int counter = from;
    int pivot = array[to];
    for (int i = from; i < to; i++)
    {
        if (array[i] < pivot) {
            swap(array[i], array[counter]);
            counter++;
        }

    }
    swap(array[counter], array[to]);
    quickSort(array, from, counter - 1);
    quickSort(array, counter + 1, to);
}

void inputArray(int* arr) {
    for (int i = 0; i < N; i++) {
        arr[i] = rand();
    }
}

void printArray(int* arr) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
        if (i % 10 == 9)
            cout << endl;
    }
}

int main() {
    int* arr = new int[N];
    inputArray(arr);
    auto start = get_time();
    quickSort(arr, 0, N - 1);
    auto finish = get_time();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    std::cout << "Elapsed time = " << duration.count() << " ms\n";
}
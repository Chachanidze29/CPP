#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
#define N 100000

//////////////   SLOW SORTING ALGORITHMS : //////////////////

//Bubble Sort Algorithm

//Best case time complexity : O(n)
//Average case time comlexity : O(n^2)
//Worst case time complexity : O(n^2)

void bubbleSort(int* arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

//Selection Sort Algorithm

//Best case time complexity : O(n^2)
//Average case time comlexity : O(n^2)
//Worst case time complexity : O(n^2)

//Minimum number of swaps

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
}

//Insertion Sort Algorithm

//Best case time complexity : O(n)
//Average case time comlexity : O(n^2)
//Worst case time complexity : O(n^2)

//Good for almost sorted array

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

///////////////   Quick Sorting Algorithms :  ////////////////////

//Merge Sort Algorithm

//Best case time complexity : O(nlogn)
//Average case time comlexity : O(nlogn)
//Worst case time complexity : O(nlogn)

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return;//returns recursively
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

//Quick Sort Algorithm

//Best case time complexity : O(nlogn)
//Average case time comlexity : O(nlogn)
//Worst case time complexity : O(n^2)

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

//Bucket Sort Algorithm

//Best case time complexity : O(n)
//Average case time comlexity : O(n)
//Worst case time complexity : O(n^2)

void bucketSort(float arr[], int n)
{

    // 1) Create n empty buckets
    vector<float>* b = new vector<float>[n];

    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

//Heap Sorting Algorithm

//Best case time complexity : O(nlogn)
//Average case time comlexity : O(nlogn)
//Worst case time complexity : O(nlogn)

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {

        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {

    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[1], arr[i]);
        heapify(arr, i, 1);

    }

}

void displayHeap(int arr[], int n)
{
    for (auto i = 1; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void inputArr(int* arr) {
    for (int i = 0; i < N; i++)
        arr[i] = rand();
}

auto get_time() { return std::chrono::high_resolution_clock::now(); }

int main() {
    int* arr = new int[N];
    inputArr(arr);
    auto start = get_time();
    heapsort(arr, N);
    auto finish = get_time();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    std::cout << "Elapsed time = " << duration.count() << " ms\n";
}
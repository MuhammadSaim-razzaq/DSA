#include<iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

int quickSelect(int arr[], int start, int end, int k) {
    int pivotIndex = partition(arr, start, end);

    if(pivotIndex == k)
        return arr[pivotIndex];
    else if(k < pivotIndex)
        quickSelect(arr, start, pivotIndex - 1, k);
    else
        quickSelect(arr, pivotIndex + 1, end, k);
}

int main() {
    int arr[] = {4, 3, 2, 1, 3, 4, 1, 75, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = n / 2;  // median index
    cout << "Median is: " << quickSelect(arr, 0, n - 1, k) << endl;

    return 0;
}

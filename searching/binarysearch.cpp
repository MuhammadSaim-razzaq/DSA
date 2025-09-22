#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2; // find middle index

        if (arr[mid] == key) {
            return mid; // found the key
        }
        else if (arr[mid] < key) {
            low = mid + 1; // search in right half
        }
        else {
            high = mid - 1; // search in left half
        }
    }
    return -1; // not found
}

int main() {
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    // 🔹 Insert at Beginning
    void insertAtBeg(int data) {
        Node* n = new Node(data);
        n->next = head;
        head = n;
    }

    // 🔹 Insert at End
    void insertAtEnd(int data) {
        Node* n = new Node(data);
        if (head == NULL) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

    // 🔹 Insert at Any Position (1-based)
    void insertAtAny(int pos, int data) {
        if (pos <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 1) {
            insertAtBeg(data);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range, inserting at end." << endl;
            insertAtEnd(data);
            return;
        }

        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    // 🔹 Delete from Beginning
    void delAtBeg() {
        if (head == NULL) {
            cout << "List empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 🔹 Delete from End
    void delAtEnd() {
        if (head == NULL) {
            cout << "List empty!" << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* pre = NULL;
        Node* post = head;

        while (post->next != NULL) {
            pre = post;
            post = post->next;
        }

        pre->next = NULL;
        delete post;
    }

    // 🔹 Delete at Any Position (1-based)
    void delAtAny(int pos) {
        if (head == NULL || pos <= 0) {
            cout << "Invalid operation!" << endl;
            return;
        }

        if (pos == 1) {
            delAtBeg();
            return;
        }

        Node* pre = NULL;
        Node* curr = head;

        for (int i = 1; i < pos && curr != NULL; i++) {
            pre = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        pre->next = curr->next;
        delete curr;
    }

    // 🔹 Search by Data (returns position)
    int searchByData(int data) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == data)
                return pos;
            temp = temp->next;
            pos++;
        }

        cout << "Data not found!" << endl;
        return -1;
    }

    // 🔹 Search by Position (1-based)
    int searchByPosition(int pos) {
        if (pos <= 0) {
            cout << "Invalid position!" << endl;
            return -1;
        }

        Node* temp = head;
        int index = 1;

        while (temp != NULL && index < pos) {
            temp = temp->next;
            index++;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return -1;
        }

        return temp->data;
    }

    // 🔹 Display
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // =====================================
    // 🔸 Helper Functions for Sorting/Searching
    // =====================================

    int length() {
        int len = 0;
        Node* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    int* toArray(int &size) {
        size = length();
        int* arr = new int[size];
        Node* temp = head;
        for (int i = 0; i < size && temp != NULL; i++) {
            arr[i] = temp->data;
            temp = temp->next;
        }
        return arr;
    }

    void updateFromArray(int* arr, int size) {
        Node* temp = head;
        for (int i = 0; i < size && temp != NULL; i++) {
            temp->data = arr[i];
            temp = temp->next;
        }
    }

    // =====================================
    // 🔸 Sorting Algorithms
    // =====================================

    void bubbleSort() {
        if (head == NULL) return;
        int n;
        int* arr = toArray(n);
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
        updateFromArray(arr, n);
        delete[] arr;
    }

    void insertionSort() {
        int n;
        int* arr = toArray(n);
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        updateFromArray(arr, n);
        delete[] arr;
    }

    void selectionSort() {
        int n;
        int* arr = toArray(n);
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx])
                    minIdx = j;
            }
            swap(arr[i], arr[minIdx]);
        }
        updateFromArray(arr, n);
        delete[] arr;
    }

    void shellSort() {
        int n;
        int* arr = toArray(n);
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
        updateFromArray(arr, n);
        delete[] arr;
    }

    void combSort() {
        int n;
        int* arr = toArray(n);
        int gap = n;
        bool swapped = true;

        while (gap != 1 || swapped) {
            gap = (gap * 10) / 13;
            if (gap < 1) gap = 1;
            swapped = false;

            for (int i = 0; i < n - gap; i++) {
                if (arr[i] > arr[i + gap]) {
                    swap(arr[i], arr[i + gap]);
                    swapped = true;
                }
            }
        }
        updateFromArray(arr, n);
        delete[] arr;
    }

    // =====================================
    // 🔸 Searching Algorithms
    // =====================================

    int binarySearch(int key) {
        int n;
        int* arr = toArray(n);
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == key) {
                delete[] arr;
                return mid + 1; // 1-based index
            } else if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        delete[] arr;
        return -1;
    }

    int interpolationSearch(int key) {
        int n;
        int* arr = toArray(n);
        int low = 0, high = n - 1;

        while (low <= high && key >= arr[low] && key <= arr[high]) {
            if (low == high) {
                if (arr[low] == key) {
                    delete[] arr;
                    return low + 1;
                }
                break;
            }
            int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));
            if (arr[pos] == key) {
                delete[] arr;
                return pos + 1;
            }
            if (arr[pos] < key)
                low = pos + 1;
            else
                high = pos - 1;
        }
        delete[] arr;
        return -1;
    }

    int linearSearch(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key)
                return pos;
            pos++;
            temp = temp->next;
        }
        return -1;
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(40);
    list.insertAtEnd(30);
    list.insertAtEnd(20);
    list.display();

    cout << "\nSorting using Bubble Sort...\n";
    list.bubbleSort();
    list.display();

    cout << "\nBinary Search (30): Position = " << list.binarySearch(30) << endl;
    cout << "Linear Search (20): Position = " << list.linearSearch(20) << endl;
    cout << "Interpolation Search (40): Position = " << list.interpolationSearch(40) << endl;

    return 0;
}

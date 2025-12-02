#include<iostream>
using namespace std;


int partation(int arr[],int start, int end){
    int idx = start -1;
    int pivoit = end;
    
    for(int i =start; i<end; i++){
        
        if(arr[i]<= arr[pivoit]){
            idx++;
            swap(arr[idx],arr[i]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}

void quick(int arr[],int start, int end){
    if(start>=end) return;

    int piviot = partation(arr, start, end);
    quick(arr,start,piviot-1);
    quick(arr,piviot+1,end);

    return;
}


int main() {
    int arr[] = {4, 3,2, 1,3,4,1,75,4,2}; // Fully descending array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quick(arr, 0, n - 1);
    
    cout << "Result: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
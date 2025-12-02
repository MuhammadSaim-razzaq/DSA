#include<iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end){
    int temp[10000];
    int i = start, j= mid+1,idx =0;

    while(i<= mid && j<= end){
        if(arr[i]<= arr[j]){
            temp[idx++]=arr[i++];
        }else{
            temp[idx++] = arr[j];
            j++;
            
        }
    }

    while(j<=end){
        temp[idx++]= arr[j++];
    }

    while(i<=mid){
        temp[idx++]= arr[i++];
    }

    for(int k =0; k<idx; k++){
        arr[start+k] = temp[k];
    }

}


void mergesort(int arr[],int start,int end){
    if(start>=end) return;

    int mid = start +(end-start)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);

    merge(arr,start,mid,end);
}

int main() {
    int arr[] = {10, 4, 1, 7, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    cout << "Sorted: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
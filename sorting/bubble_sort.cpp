#include<iostream>
using namespace std;
void bubbleSort(int arr[],int size){
    for(int i=0 ; i<size-1;i++){
        bool swapped = false;
        for(int j= 0 ;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            return;
        }
    }
}

int main(){
    int arr[]= {2,5,1,3,5,7,3,7,9,9,2,3,53,2,4,2,57,78,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}
#include<iostream>
using namespace std;

void combSort(int arr[],int size){
    int gap = size;
    const double shrink = 1.3;
    bool swapped = true;

    while(gap>1 || swapped){
        gap = (int)gap/shrink;
        if(gap<1) gap =1;
        swapped = false;

        for(int i=0; i+gap<size; i++){
            if(arr[i]>arr[i+gap]){
                swap(arr[i],arr[i+gap]);
                swapped = true;
            }
        }
    }
}

int main(){
    int arr[]= {2,5,1,3,5,7,3,7,9,9,2,3,53,2,4,2,57,78,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    combSort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}
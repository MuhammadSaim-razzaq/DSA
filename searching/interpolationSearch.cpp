#include<iostream>
using namespace std;

int InterpolationSearch(int arr[],int size,int key){
    int low = 0;
    int high = size-1;
    while(low<=high && key>=arr[low] && key<=arr[high]){
        if(low==high){
            if(key==arr[low]){
                return low;
            }
            return -1;
        }

        int pos = low+((key-arr[low]/arr[high]-arr[low])*(high-low));

        if(arr[pos]== key) return key;
        
        if(pos >= low){
            low = pos+1;
        }else{
            high = pos-1;
        }
    }
};

int main(){
    int arr[]= {2,5,1,3,5,7,3,7,9,9,2,3,53,2,4,2,57,78,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<InterpolationSearch(arr,size,7);
}
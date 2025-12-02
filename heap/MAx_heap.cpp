#include<iostream>
using namespace std;

class MaxHeap{

    int* arr;
    int size;  //total elements in heap
    int total_size; //total size of array

    public:

    MaxHeap(int n){
        arr = new int(n);
        size = 0;
        total_size = n;
    }

    void insert(int val){
        //if size is full
        if(size == total_size){
            cout<<"Heap overflow";
            return;
        }
        //not full
        arr[size] = val;
        int idx = size;
        size++;

        //compare it with parents
        while(idx>0 && arr[(idx-1)/2]< arr[idx]){
            swap(arr[idx],arr[(idx-1)/2]);
            idx = (idx-1)/2;
        }
        
    }


    void heapifyDown(int idx){
        int largest = idx;
        //largest between the 3 of them
        int left = 2*idx +1;
        int right = 2*idx +2;
    
        if(left<size && arr[left]>arr[largest])
        largest = left;
    
        if(right<size && arr[right]>arr[largest])
        largest = right;
    
          if(largest != idx){
            swap(arr[idx],arr[largest]);
            heapifyDown(largest);
        }  
    }   

    void Delete(){
        if(size==0){
            return;
        }
        arr[0]= arr[size-1];
        size--;

        if(size == 0) return;

        heapifyDown(0);
    }


};  


int main(){
    MaxHeap H1(6);
    H1.insert(3);
    H1.insert(4);
}
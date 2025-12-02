#include<iostream>
using namespace std;

int sum(int num){
    int sum =0;
    while(num>0){
        sum+= num%10;
        num/=10;
    }
    return sum;
}

void merge(int arr[], int start,int mid, int end){
    int s1 = mid -start +1;
    int s2 = end - mid;

    int left[s1],right[s2];

    for(int i=0; i<s1; i++){
        left[i]= arr[start+i];
    }

    for(int i=0; i<s2; i++){
        right[i]= arr[mid+1+i];
    }

    int i =0, j = 0, idx=start;

    while(i<s1 && j< s2){
        if(sum(left[i])<sum(right[j])){
            arr[idx++]= left[i++];
        }else{
            arr[idx++] = right[j++];
        }
    }

    while(i<s1) arr[idx++] = left[i++];
    while(j<s2) arr[idx++] = right[j++];

}



void mergesort(int arr[], int start, int end){
    if(start>=end) return;

    int mid = start + (end - start)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);

    merge(arr,start,mid,end);
}

int main() {
    int arr[] = {291, 124, 39, 231, 473, 601, 101};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// #include<iostream>
// using namespace std;

// int sum(int num){
//     int sum = 0;
//     while(num > 0){
//         sum += num % 10;
//         num /= 10;
//     }
//     return sum;
// }

// void merge(int arr[], int start, int mid, int end){
//     int s1 = mid - start + 1;
//     int s2 = end - mid;  // Fixed: end - mid (not end - (mid+1) +1)
    
//     int left[s1], right[s2];

//     for(int i = 0; i < s1; i++){
//         left[i] = arr[start + i];
//     }

//     for(int i = 0; i < s2; i++){
//         right[i] = arr[mid + 1 + i];  // Fixed: right[i] not left[i]
//     }

//     int i = 0, j = 0, idx = start;  // Fixed: i=0, j=0, idx=start

//     while(i < s1 && j < s2){  // Fixed: condition
//         if(sum(left[i]) <= sum(right[j])){  // Fixed: proper comparison
//             arr[idx++] = left[i++];
//         } else {
//             arr[idx++] = right[j++];
//         }
//     }

//     while(i < s1) arr[idx++] = left[i++];  // Fixed: i < s1
//     while(j < s2) arr[idx++] = right[j++];  // Fixed: j < s2
// }

// void mergesort(int arr[], int start, int end){
//     if(start >= end) return;

//     int mid = start + (end - start) / 2;
//     mergesort(arr, start, mid);
//     mergesort(arr, mid + 1, end);
//     merge(arr, start, mid, end);
// }

// int main() {
//     int arr[] = {291, 124, 39, 231, 473, 601, 101};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     mergesort(arr, 0, n - 1);

//     cout << "Sorted Array: ";
//     for(int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

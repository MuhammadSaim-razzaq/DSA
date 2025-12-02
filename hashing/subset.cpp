// Given two arrays a[] and b[] of size m and n respectively, the task is to determine whether b[] is a subset of a[]. Both arrays are not sorted, and elements are distinct.

// Examples: 

// Input: a[] = [11, 1, 13, 21, 3, 7], b[] = [11, 3, 7, 1] 
// Output: true

// Input: a[]= [1, 2, 3, 4, 5, 6], b = [1, 2, 4] 
// Output: true

// Input: a[] = [10, 5, 2, 23, 19], b = [19, 5, 3] 
// Output: false


//brute force

#include<iostream>
using namespace std;
int main(){
    int a[] = {12,2,4,5,6,7};
    int b[] = {12,45};
    int a_size= sizeof(a)/sizeof(a[0]);
    int b_size= sizeof(b)/sizeof(b[0]);

    int count=0;
    for(int i= 0; i<b_size;i++){
        if(count==b_size) break;
        for(int j =0; j<a_size; j++){
            if(b[i]==a[j]){
                count++;
            }
        }
    }

    if(count == b_size){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}



// [Better Approach] Using Sorting and Two Pointer
// Sort both arrays and use two pointers to traverse them. If the current element of a[] is smaller, move the pointer in a. If the elements match, move both pointers. If the current element of a[] is greater than b[], then b[j] is missing in a[], so return false.


// #include <bits/stdc++.h>
// using namespace std;

// bool isSubset(vector<int>& a, vector<int>& b) {
//     // Sort both arrays
//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());

//     int i = 0, j = 0;
//     int m = a.size(), n = b.size();

//     while (i < m && j < n) {
//         if (a[i] < b[j]) {
//             i++;   // move in a to catch up
//         }
//         else if (a[i] == b[j]) {
//             i++;
//             j++;   // matched one element from b
//         }
//         else {
//             // a[i] > b[j] → means b[j] is missing
//             return false;
//         }
//     }
  
//     return (j == n); // all b[] matched
// }

// int main() {
//     vector<int> a = {11, 1, 13, 21, 3, 7};
//     vector<int> b = {11, 3, 7, 1};

//     if (isSubset(a, b)) cout << "true\n";
//     else cout << "false\n";

//     return 0;
// }




// [Expected Approach] Using Hashing- O(m + n) Time and O(m) Space
// We can use a hash set to store elements of a[], this will help us in constant time complexity searching. We first insert all elements of a[] into a hash set. Then, for each element in b[], we check if it exists in the hash set.


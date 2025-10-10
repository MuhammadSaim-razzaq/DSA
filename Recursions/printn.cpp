#include<iostream>
using namespace std;

void ndecreasing(int n){
    if(n==0){
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    return ndecreasing(n-1);
}


int main(){
    int n =5;
    ndecreasing(n);
    
}
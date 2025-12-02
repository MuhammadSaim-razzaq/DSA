#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<char> reverse;
    char array[]={'h','e','l','l','o'};
    for(int i =0 ; i<5; i++){
        reverse.push(array[i]);
    }
    while(!reverse.empty()){
        cout<<reverse.top();
        reverse.pop();
    }
}
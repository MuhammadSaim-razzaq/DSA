#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int gcd=0;
    bool l = a>b;
    if(l == false){
        for(int i=1 ;i<b;i++){
            if(a%i==0 &&  b%i==0 ){
                if(i>gcd){
                    gcd = i;
                }
            }
        }
    }else{
        for(int i=1 ;i<a;i++){
            if(a%i==0 &&  b%i==0 ){
                if(i>gcd){
                    gcd = i;
                }
            }
        }
    }
    cout<<gcd;
}
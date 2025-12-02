#include<iostream>
#include<stack>
using namespace std;


bool isvalid(const string& s){
    stack<char> ch;
    for(int i =0; i<s.length();i++){
        if(s[i]== '('){
            ch.push(s[i]);
        }else{
            if(s[i]==')'){
                if(ch.size()== 0){
                    cout<<"invalid";
                    return false;
                }else if(ch.top()== '('){
                    cout<<"valid";
                    return true;
                }
            }else{
                if(s[i]>= 'a' && s[i]<='z' || s[i]>= 'A' && s[i]<= 'Z'|| s[i]== '+'|| s[i]=='-'
                ||s[i]=='*'  ||s[i]=='/'){
                    if((i+1)== s.length()){
                        cout<<"invalid";
                        return false;
                    }
                    continue;
                }
                cout<<"invalid";
                return false;
            }
        }
    }
}
int main(){
    string s;
    cin>>s;
    isvalid(s);
}
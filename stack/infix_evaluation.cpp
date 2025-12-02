#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> val;
    stack<char>operat;
    string infix_string;
    cin>>infix_string;
    for(char c : infix_string){
        char ch = c;
        int ascii = (int)ch;
        //'0'->48  '9'->57
        if(ascii>=48 && ascii<=57){
            val.push(ascii-48);
        }else if(operat.size()==0){
            operat.push(ch);
        }else{
            if(ch == '+' || ch == '-'){
                int v2 = val.top();  val.pop();
                int v1 = val.top();  val.pop();

                if(operat.top()== '-') val.push(v1-v2);
                if(operat.top()== '+') val.push(v1+v2);
                if(operat.top()== '*') val.push(v1*v2);
                if(operat.top()== '/') val.push(v1/v2);

                operat.pop();
            }
            if(ch == '*' || ch == '/'){
                if(operat.top()== '*' || operat.top()== '/'){
                    
                }
            }
        }
    }
}
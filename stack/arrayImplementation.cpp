#include<iostream>
using namespace std;
class Stack{
    int*arr;
    int size;
    int top =-1;
public:
    Stack(int s){
        size =s;
        arr = new int[size];
    }

    string push_stack(int val){
        if(top < size-1){
            top++;
            arr[top] = val;
            return "value added successfully";
        }
        return "stack overflow occured";
    }
    
    string pop_stack(){
        if(top>-1){
            top--;
            return "poped successfully";
        }
        return "Stack underflow occured";
    }

    string Top_val(){
        if(top<0){
            return "No value in stack";
        }else{
            cout<<arr[top];
        }
        return " ";
    }

    bool Is_empty(){
        return (top==-1);
    }
};


int main(){
    Stack s(3);
    cout<<s.pop_stack()<<endl;
    for(int i =0; i<3;i++){
        s.push_stack(1);
    }
    cout<<s.push_stack(1)<<endl;
    cout<<s.Top_val()<<endl;
    if(s.Is_empty()){
        cout<<"stack empty";
    }else{
        cout<<"stack Not Empty";
    };

    
}
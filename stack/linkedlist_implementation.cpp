#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d):data(d),next(NULL){};
};

class Stack{
public:   
    Node* Top= NULL;
    int size = 0 ;

    void push_stack(int d){
        Node* n = new Node(d);
        n->next =Top;
        Top = n;
        size++;
    }

    string pop_stack(){
        if(Top == NULL){
            return "Stack underflow";
        }
        Node* temp =Top;
        Top= Top->next;
        delete temp;
        size--;

        return "Data is successfully popped";
    }

    void Top_val(){
        if(Top == NULL){
            cout<<"No data in stack";
            return;
        }else{
            cout<<Top->data<<endl;
            return;
        }
    }

    bool Is_empty(){
            return(Top == NULL);
    }

    int Is_size(){
        return size;
    }


};


int main(){
    Stack s;
    s.push_stack(1);

    if(s.Is_empty()){
        cout<<"Stack empty";
    }else{
        cout<<"Stack Not empty";
    }

}

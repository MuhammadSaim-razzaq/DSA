#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node *right;
    Node(int data):data(data){
        left = NULL;
        right = NULL;
    }
};

int main(){
    queue<Node*>Tree;
    cout<<"Enter root";
    int root;
    cin>>root;
    Node* root_T = new Node(root);
    Tree.push(root_T);
    
    while(!Tree.empty()){
        Node* tmp = Tree.front();
        Tree.pop();
        int leftval,rightval;
        cout<<"Enter the left child of "<<tmp->data<<":"<<endl;
        cin>>leftval;
        if(leftval != -1){
            Node* left= new Node(leftval);
            tmp->left = left;
            Tree.push(tmp->left);
        }else{
            tmp->left = NULL;
        }
        cout<<"Enter the right child of "<<tmp->data<<":"<<endl;
        cin>>rightval;
        if(rightval != -1){
            Node* right= new Node(rightval);
            tmp->right = right;
            Tree.push(tmp->right);
        }else{
            tmp->right = NULL;
        }
    }

}
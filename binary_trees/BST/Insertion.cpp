#include<iostream>
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

Node* insert(Node*root, int val){
    if(!root) return new Node(val);
    
    if(val>root->data){
        root->right = insert(root->right,val);
    }else{
        root->left = insert(root->left,val);
    }
    return root;
};

void inorder(Node* root){
    if(!root)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int arr[]= {1,2,3,4,5,6};
    Node* root = NULL;
    for(int i =0; i<6; i++){
        root= insert(root ,arr[i]);
    } 
    inorder(root);
}
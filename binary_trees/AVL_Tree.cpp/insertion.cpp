#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        int height;
    Node(int data):height(1),data(data),left(NULL),right(NULL){}

};

int getheight(Node* root){
    if(!root) return 0;
    return root->height;
};

int getbalance(Node* root){
    if(!root) return 0;
    return (getheight(root->left)-getheight(root->right));
};

Node* rightrotation(Node* root){
    Node* child = root->left;
    Node* rightchild = child->right;
    child->right = root;
    root->left = rightchild;
    //update root height
    root->height =  1+ max(getheight(root->left),getheight(root->right));
    //updat child height
    child->height = 1 + max(getheight(child->left),getheight(child->right));
    return child;
}

Node* leftrotation(Node* root){
    Node* child = root->right;
    Node* leftchild = child->left;
    child->left = root;
    root->right = leftchild;
    //update root height
    root->height =  1+ max(getheight(root->left),getheight(root->right));
    //updat child height
    child->height = 1 + max(getheight(child->left),getheight(child->right));    

    return child;
}


// Duplicates are not allowed
Node* insert(Node* root,int data){
    if(!root) return new Node(data);

    if(data > root->data)       root->right= insert(root->right,data);
    else if(data<root->data)    root->left = insert(root->left,data);
    else                        return root;

    root->height = 1+ max(getheight(root->left),getheight(root->right));

    int balance = getbalance(root);
     
    //left left case
    if(balance>1 && data<root->left->data){
       return rightrotation(root);
    }
    //right right case
    else if(balance< -1 && data>root->right->data){
        return leftrotation(root);
    }
    //left right
    else if(balance>1 && data>root->left->data){
       root->left= leftrotation(root->left);
       return rightrotation(root);
    }
    //right left
    else if(balance< -1 && data<root->right->data){
       root->right= rightrotation(root->right);
       return leftrotation(root);
    }
    // no balance
    else{
        return root;
    }
};


void display(Node* root){
    if(!root) return;
    
    display(root->left);
    cout<<root->data<<" "; 
    display(root->right);
    return;
};

int main(){
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    display(root);
}
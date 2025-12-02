#include<iostream>
#include<vector>
using namespace std;

void inorder(Node* root,vector<int>&ans){
    if(!root) return;

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);

    return;
}

bool isbst(){
    vector<int>ans;
    inorder(root,ans);

    for(int i=0; i<ans.size(), i++){
        if(arr[i]> arr[i+1]) return 0;
    }
    return 1;
}

void inorder(Node* root,int arr[],int idx){
    if(!root) return;

    inorder(root->left,arr);
    arr[idx++]=root->data;
    inorder(root->right,arr);

    return;
}


bool isbst(Node* root){
    int arr[1000];
    inorder(root,arr,0);

    for(int i=0; i<1000;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}


int main(){

}
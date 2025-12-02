#include<iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* left,*right;
    Node(int x):data(x), left(NULL), right(NULL) {}
};

void MinDist(Node* root,int& prev, int& ans){
    if(!root) return;

    MinDist(root->left,prev,ans);
    if(prev != INT_MIN){
        ans = min(ans,root->data- prev);
    }
    prev = root->data;
    MinDist(root->right,prev,ans);

    return;
}
int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    int prev = INT_MIN;
    int ans = INT_MAX;

    MinDist(root, prev, ans);

    cout << "Minimum distance between any two nodes = " << ans << endl;

    return 0;
}
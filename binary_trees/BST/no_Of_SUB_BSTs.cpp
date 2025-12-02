#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* left,*right;
    Node(int x):data(x), left(NULL), right(NULL) {}
};

struct Info{
    bool isBst;
    int minVal;
    int maxVal;
};

Info solve(Node* root, int &totalBSTs){
    if(!root){
        return {true,INT_MAX,INT_MIN};
    }

    Info left = solve(root->left,totalBSTs);
    Info right = solve(root->right,totalBSTs);

    Info curr;

    if(left.isBst && right.isBst && left.maxVal<root->data && root->data<right.minVal){
        curr.isBst = true;
        totalBSTs++;
    }else {
        curr.isBst = false;
    }

    curr.minVal = min(root->data,left.minVal);
    curr.maxVal = max(root->data,right.maxVal);

    return curr;
}

int countBSTs(Node* root) {
    int total = 0;
    solve(root, total);
    return total;
}

int main() {

    /*
           50
          /  \
        25    7
       /  \
      2    38
    */

    Node* root = new Node(50);
    root->left = new Node(25);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(38);

    cout << "\nTotal BST Subtrees in Given Tree: " << countBSTs(root) << endl;

    return 0;
}
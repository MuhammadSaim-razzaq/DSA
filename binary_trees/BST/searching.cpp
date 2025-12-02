#include<iostream>
using namespace std;

// Linked List Node
class ListNode {
    public:
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(NULL) {}

};

// BST Node
class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class Convert{
    public:
        ListNode* Middle(ListNode* head,ListNode** prev){
            * prev = NULL;
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast && fast->next){
                *prev = slow;
                slow= slow->next;
                fast = fast ->next->next;
            }

            return slow;
        }

        TreeNode* sortedListToBST(ListNode* head){
            if(!head) return NULL;
            if(!head->next) 
            return new TreeNode(head->data);

            ListNode* prev = NULL;
            ListNode*  mid = Middle(head,&prev);

            if(prev) prev->next =NULL;
            TreeNode* root = new TreeNode(mid->data);

            root->left = sortedListToBST(head);
            root->right = sortedListToBST(mid->next);
            return root;
        }


};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 

void printTree(TreeNode* root, int space = 0, int indent = 5) {
    if (root == nullptr)
        return;

    // Increase distance between levels
    space += indent;

    // Print right subtree first
    printTree(root->right, space);

    // Print current node after spaces
    cout << endl;
    for (int i = indent; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    // Print left subtree
    printTree(root->left, space);
}

bool search(TreeNode* root,int data){
    if(root== NULL) return 0;
    
    if(root->data == data) return 1;

    if(root->data>data){
        return search(root->left,data);
    }else{
        return search(root->right,data);
    }
}


int main(){

    ListNode* head = new ListNode(5);
    head->next = new ListNode(10);
    head->next->next = new ListNode(15);
    head->next->next->next = new ListNode(20);
    head->next->next->next->next = new ListNode(25);

    Convert obj;
    TreeNode* root = obj.sortedListToBST(head);

    
    cout << "Inorder Traversal of Balanced BST: ";
    inorder(root);
    printTree(root);
    cout<<search(root,10);

}
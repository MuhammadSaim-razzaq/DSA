#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to insert a new node in BST
Node* insert(Node* root, int data) {
    if (root == NULL)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Helper to find sum of first k and k-1 minimum elements
void helper(Node* root, int &k, int &k1, int &sumK, int &sumK1) {
    if (!root  || (k <= 0)) return;

    // Traverse left subtree
    helper(root->left, k, k1, sumK, sumK1);

    // Process current node
    if (k > 0) {
        sumK += root->data;
        k--;
    }
    if (k1 > 0) {
        sumK1 += root->data;
        k1--;
    }

    // Traverse right subtree
    helper(root->right, k, k1, sumK, sumK1);
}

// Wrapper function
void findKthSmallest(Node* root, int k) {
    int sumK = 0, sumK1 = 0;
    

    int k1 = k-1;
    helper(root, k, k1, sumK, sumK1);

    int kthElement = sumK - sumK1;

    cout << "Sum of first " << k << " minimum elements: " << sumK << endl;
    cout << "Sum of first " << k - 1 << " minimum elements: " << sumK1 << endl;
    cout << "The " << k << "-th smallest element is: " << kthElement << endl;
}

// Main function
int main() {
    Node* root = NULL;

    // Build BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int k;
    cout << "Enter k: ";
    cin >> k;

    findKthSmallest(root, k);

    return 0;
}


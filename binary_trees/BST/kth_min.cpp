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

// Insert function to build BST
Node* insert(Node* root, int data) {
    if (root == NULL)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Helper function
void helper(Node* root, int &k, int &sum) {
    if (!root || k <= 0) return;

    helper(root->left, k, sum);

    if (k > 0) {
        sum += root->data;
        k--;
    }

    if (k > 0)
        helper(root->right, k, sum);

    return ;
}

// Wrapper function
int sumKthMinElements(Node* root, int k) {
    int sum = 0;
    helper(root, k, sum);
    return sum;
}

// Main function
int main() {
    Node* root = NULL;

    // Create BST
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

    int result = sumKthMinElements(root, k);
    cout << "Sum of first " << k << " minimum elements = " << result << endl;

    return 0;
}

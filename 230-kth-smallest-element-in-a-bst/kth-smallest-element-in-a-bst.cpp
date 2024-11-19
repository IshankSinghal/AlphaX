// INORDER TRAVERSAL with EXTRA SPACE:

class Solution {
public:
    // Function to perform inorder traversal and collect values in the array
    void inorder(TreeNode* root, vector<int> &arr) {
        if (root == NULL) {
            return; // Return immediately if the current node is NULL
        }

        inorder(root->left, arr);  // Traverse the left subtree
        arr.push_back(root->val); // Store the current node's value
        inorder(root->right, arr); // Traverse the right subtree
    }

    // Function to find the k-th smallest element in the BST
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr; // Array to store elements in sorted order
        inorder(root, arr); // Perform inorder traversal
        return arr[k-1]; // Return the k-th smallest element
    }
};

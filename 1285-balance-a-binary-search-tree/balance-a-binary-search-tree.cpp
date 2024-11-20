class Solution {
public:
    // Perform in-order traversal to collect the elements of the BST in sorted order
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) 
            return; // Base case: If the node is null, stop the recursion

        inorder(root->left, arr);     // Traverse the left subtree
        arr.push_back(root->val);    // Add the current node's value to the array
        inorder(root->right, arr);   // Traverse the right subtree
    }

    // Convert the sorted array into a balanced BST
    TreeNode* inorderToBST(int s, int e, vector<int>& arr) {
        if (s > e) 
            return NULL; // Base case: If start index exceeds end index, return null

        int mid = (s + e) / 2;       // Find the middle element to use as the root
        TreeNode* root = new TreeNode(arr[mid]); // Create a new node with the middle value
        root->left = inorderToBST(s, mid - 1, arr); // Recursively build the left subtree
        root->right = inorderToBST(mid + 1, e, arr); // Recursively build the right subtree

        return root;
    }

    // Main function to balance the BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;             // Vector to store the sorted elements of the BST
        inorder(root, arr);          // Fill the vector with in-order traversal
        return inorderToBST(0, arr.size() - 1, arr); // Build and return the balanced BST
    }
};

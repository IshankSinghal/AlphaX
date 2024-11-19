/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to find the k-th smallest element
    int solve(TreeNode* root, int &i, int k) {
        if (root == NULL) return -1; // Base case: if node is NULL, return -1

        // Search in the left subtree
        int left = solve(root->left, i, k);
        if (left != -1) { // If k-th smallest is found in left subtree, return it
            return left;
        }

        // Increment the counter for the current node
        i++;
        if (i == k) return root->val; // If current node is the k-th smallest, return its value

        // Search in the right subtree
        return solve(root->right, i, k);
    }

    // Main function to find the k-th smallest element
    int kthSmallest(TreeNode* root, int k) {
        int i = 0; // Counter for tracking the current element's rank
        return solve(root, i, k); // Call the helper function
    }
};

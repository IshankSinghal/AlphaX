/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to calculate the height of the tree and update the diameter
    int solve(TreeNode* root, int& diameter) {
        // Base case: If the current node is null, return height as 0
        if (!root) return 0;

        // Recursively find the height of the left subtree
        int leftHeight = solve(root->left, diameter);

        // Recursively find the height of the right subtree
        int rightHeight = solve(root->right, diameter);

        // Calculate the diameter for the current node
        // The diameter is the sum of the heights of the left and right subtrees
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current node
        // Height of the current node is 1 + the maximum of the heights of its left and right subtrees
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to compute the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // Initialize the diameter to 0
        int diameter = 0;

        // Call the helper function to compute the diameter
        // This function will also compute the height of the tree
        solve(root, diameter);

        // Return the computed diameter
        return diameter;
    }
};

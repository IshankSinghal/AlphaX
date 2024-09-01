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
    // Function to compute the maximum depth of a binary tree
    int maxDepth(TreeNode* root) {
        // Base case: if the current node is null, return 0 (no depth)
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the depth of the left subtree
        int left = maxDepth(root->left);
        // Recursively calculate the depth of the right subtree
        int right = maxDepth(root->right);

        // The depth of the current node is the maximum of the depths of its subtrees plus 1
        int ans = max(left, right) + 1;

        // Return the calculated depth for the current node
        return ans;
    }
};

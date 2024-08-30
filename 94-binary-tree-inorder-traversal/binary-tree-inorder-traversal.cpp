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

// MORRIS TRAVERSAL
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;
    TreeNode* pre;

    while (curr != NULL) {
        // Case 1: If there is no left child, visit this node and go to the right child
        if (curr->left == NULL) {
            ans.push_back(curr->val); // Add current node value to result
            curr = curr->right; // Move to the right child
        } else {
            // Case 2: Find the rightmost node in the left subtree or thread to current node
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }

            if (pre->right == NULL) {
                // Establish thread to current node and move to the left child
                pre->right = curr;
                curr = curr->left;
            } else {
                // Remove the thread and visit the current node
                pre->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}

};
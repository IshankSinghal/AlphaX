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

//MORRIS TRAVERSAL
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;  // Vector to store the preorder traversal result
    if (!root)        // If the root is null, return an empty vector
        return ans;

    TreeNode* curr = root;  // Start with the root node
    TreeNode* pre;          // Pointer to track the predecessor node

    while (curr) {
        if (!curr->left) {  // If there is no left child
            ans.push_back(curr->val);  // Visit the current node and add its value to the result
            curr = curr->right;        // Move to the right child
        } else {
            // Find the inorder predecessor of the current node (rightmost node in the left subtree)
            pre = curr->left;
            while (pre->right && pre->right != curr) {
                pre = pre->right;
            }

            if (!pre->right) {  // If the predecessor's right is null, establish a thread
                pre->right = curr;  // Create a thread to the current node
                ans.push_back(curr->val);  // Visit the current node and add its value to the result
                curr = curr->left;  // Move to the left child
            } else {  // If a thread already exists
                pre->right = NULL;  // Remove the thread
                curr = curr->right;  // Move to the right child
            }
        }
    }

    return ans;  // Return the result containing the preorder traversal
}

};
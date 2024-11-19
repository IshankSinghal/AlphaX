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
    // Helper function to find the minimum value in a BST (used for successor replacement)
    int minVal(TreeNode* root) {
        // The minimum value in a BST is located in the leftmost node
        if (root->left == NULL)
            return root->val;

        return minVal(root->left);
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: if the root is null, return null
        if (root == NULL)
            return root;

        // If the key to be deleted matches the current node's value
        else if (root->val == key) {
            // Case 1: Node has no children
            if (root->left == NULL && root->right == NULL) {
                delete root; // Free memory
                return NULL; // Return null to remove the node
            }

            // Case 2: Node has only a left child
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left; // Save the left child
                delete root; // Free the current node
                return temp; // Return the left child as the new subtree root
            }

            // Case 3: Node has only a right child
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right; // Save the right child
                delete root; // Free the current node
                return temp; // Return the right child as the new subtree root
            }

            // Case 4: Node has two children
            if (root->left != NULL && root->right != NULL) {
                // Find the minimum value in the right subtree (inorder successor)
                int mini = minVal(root->right);
                root->val = mini; // Replace the current node's value with the successor
                // Recursively delete the successor node
                root->right = deleteNode(root->right, mini);
                return root; // Return the current node
            }
        }

        // If the key is greater than the current node's value, go to the right subtree
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        // If the key is smaller than the current node's value, go to the left subtree
        else {
            root->left = deleteNode(root->left, key);
            return root;
        }

        return root; // Redundant return statement (all cases are handled above)
    }
};

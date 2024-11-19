//RECURSION METHOD:

class Solution {
public:
    // Function to find the Lowest Common Ancestor (LCA) of two nodes, p and q, in a Binary Search Tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If the root is null, there's no LCA, return null
        if (root == NULL) 
            return NULL;

        // If both p and q are smaller than the current root, the LCA must be in the left subtree
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If both p and q are greater than the current root, the LCA must be in the right subtree
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If the root's value is between p and q, or equal to one of them, then the current root is the LCA
        return root;
    }
};

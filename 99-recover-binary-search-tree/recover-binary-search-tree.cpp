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
    TreeNode* first = nullptr;
    TreeNode* last = nullptr;
    TreeNode* temp = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }

        inorder(root->left);
        // arr.push_back(root->val);

        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;
                temp = root;
            } else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        // vector<int> arr;
        inorder(root);

        if (first && last) {
            swap(first->val, last->val);
        } else if (first && temp) {
            swap(first->val, temp->val);
        }
        // sort(arr.begin(),arr.end());
    }
};
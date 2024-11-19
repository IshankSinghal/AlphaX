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
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == NULL) {
            return; // Return immediately if the current node is NULL
        }

        inorder(root->left, arr);  // Traverse the left subtree
        arr.push_back(root->val);  // Store the current node's value
        inorder(root->right, arr); // Traverse the right subtree
    }

    int findSecondMinimumValue(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);

        sort(arr.begin(),arr.end());
        int ans=-1;
        for(int i =0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]) continue;
            else{
                ans = arr[i+1];
                break;
            }
        }
        return ans;
    }
};
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
    int widthOfBinaryTree(TreeNode* root) {
    // Queue to store nodes along with their corresponding index
    queue<pair<TreeNode*, int>> q;
    
    // Push the root node with an initial index of 0
    q.push({root, 0});

    int ans = 0; // Variable to keep track of the maximum width

    // BFS traversal of the tree
    while (!q.empty()) {
        int n = q.size(); // Number of nodes at the current level
        int min_ind = q.front().second; // Index of the leftmost node at this level
        int str, end; // Variables to store the first and last indices at this level

        for (int i = 0; i < n; i++) {
            TreeNode* front = q.front().first; // Current node
            // Normalize the current index by subtracting min_ind to prevent overflow
            int curr_ind = q.front().second - min_ind; 
            q.pop(); // Remove the node from the queue

            if (i == 0) str = curr_ind; // Set str to the first index at this level
            if (i == n - 1) end = curr_ind; // Set end to the last index at this level

            // If the left child exists, push it to the queue with index 2 * curr_ind + 1
            if (front->left) {
                q.push({front->left, (long long)2 * curr_ind + 1});
            }

            // If the right child exists, push it to the queue with index 2 * curr_ind + 2
            if (front->right) {
                q.push({front->right, (long long)2 * curr_ind + 2});
            }
        }

        // Calculate the width of the current level and update the maximum width
        ans = max(ans, end - str + 1);
    }

    return ans; // Return the maximum width of the binary tree
}

};
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    // Map to store nodes at each horizontal distance and level
    map<int, map<int, vector<int>>> mpp;
    // Queue for level order traversal, storing the node and its (hd, lvl)
    queue<pair<TreeNode*, pair<int, int>>> q;
    vector<vector<int>> ans;

    q.push({root, {0, 0}});

    while (!q.empty()) {
        pair<TreeNode*, pair<int, int>> temp = q.front();
        q.pop();

        TreeNode* frontNode = temp.first;

        int hd = temp.second.first;  // Horizontal distance from root
        int lvl = temp.second.second; // Level of the node

        // Insert the node's value into the map at the correct (hd, lvl)
        mpp[hd][lvl].push_back(frontNode->val);

        // Add left child to the queue with updated hd and lvl
        if (frontNode->left) {
            q.push({frontNode->left, {hd - 1, lvl + 1}});
        }
        // Add right child to the queue with updated hd and lvl
        if (frontNode->right) {
            q.push({frontNode->right, {hd + 1, lvl + 1}});
        }
    }

    // Traverse the map and build the result vector
    for (auto i : mpp) {
        vector<int> col;
        for (auto j : i.second) {
            // Sort the nodes at the same (hd, lvl)
            sort(j.second.begin(), j.second.end());
            col.insert(col.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}

};
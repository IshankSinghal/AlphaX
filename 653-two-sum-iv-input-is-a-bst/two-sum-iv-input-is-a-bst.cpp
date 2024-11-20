class Solution {
public:
    // Helper function to perform in-order traversal of the tree
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == NULL) 
            return; // Base case: If the node is null, stop the recursion

        inorder(root->left, arr);  // Traverse the left subtree
        arr.push_back(root->val); // Add the current node's value to the array
        inorder(root->right, arr); // Traverse the right subtree
    }

    // Main function to check if there exist two numbers in the tree that sum to 'k'
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;             // Vector to store elements of the tree in sorted order
        inorder(root, arr);          // Perform in-order traversal to fill the vector

        int i = 0, j = arr.size() - 1; // Two pointers: i (start) and j (end) of the sorted vector

        // Use two-pointer technique to find if two elements sum to k
        while (i < j) {
            int sum = arr[i] + arr[j]; // Calculate the sum of the two elements

            if (sum == k)              // If the sum equals k, return true
                return true;
            else if (sum < k)          // If the sum is less than k, move the left pointer to increase the sum
                i++;
            else                       // If the sum is greater than k, move the right pointer to decrease the sum
                j--;
        }

        return false; // Return false if no such pair is found
    }
};

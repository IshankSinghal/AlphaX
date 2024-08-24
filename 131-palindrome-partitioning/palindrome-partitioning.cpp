class Solution {
public:

    // Function to check if a substring is a palindrome
    bool isPalin(string s, int l, int r) {
        // Check characters from both ends towards the center
        while (l <= r) {
            // If characters at current positions don't match, it's not a palindrome
            if (s[l] != s[r]) return false;
            l++;  // Move left pointer to the right
            r--;  // Move right pointer to the left
        }
        // If all characters matched, it's a palindrome
        return true;
    }

    // Recursive function to generate all possible palindrome partitions
    void solve(string s, int ind, vector<string> palin, vector<vector<string>>& ans) {
        // Base case: If the entire string has been partitioned
        if (ind == s.size()) {
            ans.push_back(palin);  // Add the current partition to the answer list
            return;
        }

        // Try to partition the string from the current index to the end
        for (int i = ind; i < s.size(); i++) {
            // Check if the substring from 'ind' to 'i' is a palindrome
            if (isPalin(s, ind, i)) {
                // If it is, add this substring to the current partition
                palin.push_back(s.substr(ind, i - ind + 1));
                // Recursively partition the remaining string starting from the next index
                solve(s, i + 1, palin, ans);
                // Backtrack: Remove the last added palindrome substring to explore other partitions
                palin.pop_back();
            }
        }
    }

    // Main function to find all palindrome partitions of the input string
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;  // To store the final list of palindrome partitions
        vector<string> palin;  // Temporary list to store the current partition
        solve(s, 0, palin, ans);  // Start the recursive partitioning from index 0
        return ans;  // Return the list of all palindrome partitions
    }
};

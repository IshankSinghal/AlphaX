class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();      // Number of rows
        int n = grid[0].size();   // Number of columns
        
        // Vectors to store the count of servers in each row and column
        vector<int> Row(m, 0);
        vector<int> Col(n, 0);

        // Calculate the total number of servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    Row[i]++;
                    Col[j]++;
                }
            }
        }

        int ans = 0; // Variable to count the number of communicating servers

        // Traverse the grid once to check which servers can communicate
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If there is a server at grid[i][j] and it can communicate
                if (grid[i][j] == 1 && (Row[i] > 1 || Col[j] > 1)) {
                    ans++;
                }
            }
        }

        return ans; // Return the count of communicating servers
    }
};

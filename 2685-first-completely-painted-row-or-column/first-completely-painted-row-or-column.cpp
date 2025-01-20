class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // Get the number of rows and columns in the matrix
        int row = mat.size();
        int col = mat[0].size();

        // Map to store the position (row, col) of each number in the matrix
        unordered_map<int, pair<int, int>> mpp;

        // Vectors to track how many unmarked elements are left in each row and
        // column
        vector<int> rowCount(row, col); // Each row initially has 'col' elements
        vector<int> colCount(col,
                             row); // Each column initially has 'row' elements

        // Populate the map with the positions of elements in the matrix
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mpp[mat[i][j]] = {i, j};
            }
        }

        // Iterate through the array to simulate marking elements
        for (int i = 0; i < arr.size(); i++) {
            int elem = arr[i];       // Current element in the array
            auto [m, n] = mpp[elem]; // Get the position (row, col) of the
                                     // element in the matrix

            // Decrease the unmarked count for the respective row and column
            rowCount[m]--;
            colCount[n]--;

            // If the row or column becomes completely marked, return the
            // current index
            if (rowCount[m] == 0 || colCount[n] == 0) {
                return i;
            }
        }

        // If no row or column is fully marked, return -1
        return -1;
    }
};

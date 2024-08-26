class Solution {
public:
    // Function to check if placing a queen at board[r][c] is safe
    bool isSafe(int r, int c, vector<string>& board, int n) {
        int dupRow = r;
        int dupCol = c;

        // Check upper diagonal on the left side
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--; c--;
        }

        // Reset row and column values to original
        r = dupRow;
        c = dupCol;

        // Check left side in the same row
        while (c >= 0) {
            if (board[r][c] == 'Q') return false;
            c--;
        }

        // Reset row and column values to original
        r = dupRow;
        c = dupCol;

        // Check lower diagonal on the left side
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r++; c--;
        }

        // If no queens are found on any of the three checks, it's safe
        return true;        
    }

    // Recursive function to solve the N-Queens problem
    void solve(int c, vector<string>& board, vector<vector<string>>& ans, int n) {

        // If all columns are filled, a valid solution is found
        if (c == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in each row of the current column
        for (int r = 0; r < n; r++) {
            // Check if placing a queen at board[r][c] is safe
            if (isSafe(r, c, board, n)) {
                // Place the queen
                board[r][c] = 'Q';
                // Recur to place queens in the next column
                solve(c + 1, board, ans, n);
                // Backtrack by removing the queen
                board[r][c] = '.';
            }
        }
    }

    // Main function to return all possible solutions to the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // To store all the solutions
        string posi(n, '.'); // A string representing an empty row
        vector<string> board(n); // The chessboard

        // Initialize the chessboard with empty rows
        for (int i = 0; i < n; i++) {
            board[i] = posi;
        }

        // Start solving from the first column
        solve(0, board, ans, n);
        return ans; // Return all the possible solutions
    }
};

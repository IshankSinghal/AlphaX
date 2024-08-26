class Solution {
public:

    // This function checks if placing the character 'c' at position (row, col) on the Sudoku board is valid.
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // Loop through each element in the row, column, and 3x3 sub-grid.
        for (int i = 0; i < 9; i++) {
            // Check the column for the same character 'c'. If found, it's not valid to place 'c' here.
            if (board[i][col] == c) return false;

            // Check the row for the same character 'c'. If found, it's not valid to place 'c' here.
            if (board[row][i] == c) return false;

            // Check the 3x3 sub-grid for the same character 'c'. If found, it's not valid to place 'c' here.
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        // If no conflicts are found, it's safe to place the character 'c' at (row, col).
        return true;
    }

    // This recursive function attempts to solve the Sudoku board by placing numbers ('1' to '9') in empty cells.
    bool solve(vector<vector<char>>& board) {
        // Iterate through each cell in the Sudoku board.
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // If an empty cell is found (denoted by '.'), try placing each number ('1' to '9') in it.
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        // Check if placing the character 'c' in the current cell is valid.
                        if (isValid(board, i, j, c)) {
                            // Place the character 'c' in the cell.
                            board[i][j] = c;

                            // Recursively attempt to solve the rest of the board.
                            if (solve(board)) return true;
                            else
                                // If placing 'c' leads to a conflict later, reset the cell to empty ('.') and try the next number.
                                board[i][j] = '.';
                        }
                    }
                    // If no number can be placed in the current cell, return false to trigger backtracking.
                    return false;
                }
            }
        }
        // If all cells are filled correctly, the board is solved and return true.
        return true;
    }

    // This function initiates the Sudoku-solving process by calling the solve function.
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

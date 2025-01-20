class Solution {
public:
    bool rotting(int row, int col, vector<vector<int>>& grid, int t) {
        bool isRotted = false;
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == t) {
                    for (auto d : dir) {
                        int nRow = i + d[0];
                        int nCol = j + d[1];

                        if (nRow >= 0 && nRow < row && nCol >= 0 &&
                            nCol < col) {
                            if (grid[nRow][nCol] == 1) {
                                grid[nRow][nCol] = t + 1;
                                isRotted = true;
                            }
                        }
                    }
                }
            }
        }

        return isRotted;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int minTime = 2;

        while (rotting(row, col, grid, minTime))
            minTime++;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return minTime - 2;
    }
};
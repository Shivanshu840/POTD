class Solution {
public:


    vector<vector<int>> matrix;
    vector<vector<int>>dp;
    int rows, cols;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1}; 
    

    int rec(int r, int c, int prevVal) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || matrix[r][c] <= prevVal) {
            return 0;
        }

        if(dp[r][c] != -1) return dp[r][c];
        int ans = 1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i]; 
            int nc = c + dc[i];
            ans = max(ans, 1 + rec(nr, nc, matrix[r][c]));
        }
        return dp[r][c] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& grid) {
        matrix = grid;
        rows = grid.size();
        cols = grid[0].size();
        int maxLen = 0;

        dp.resize(rows, vector<int>(cols,-1));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                maxLen = max(maxLen, rec(i, j, -1));
            }
        }
        return maxLen;
    }
};
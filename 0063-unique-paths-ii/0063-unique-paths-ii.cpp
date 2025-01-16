class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& grid) {

        if(i<0 || j<0) return 0;
        if (grid[i][j] == 1)
            return 0;

        if (i == 0 && j == 0) {

            if(grid[i][j] == 0) return 1;

            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = solve(i - 1, j, grid);
        int down = solve(i, j - 1, grid);

        return dp[i][j] = up + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.resize(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, obstacleGrid);
    }
};
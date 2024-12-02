class Solution {
public:
    vector<vector<int>>dp;
    int solution(int m,int n, vector<vector<int>>&grid){
        if(m==0 && n==0){
            return grid[m][n];
        }
        if(m<0 || n<0){
            return 1e9;
        }
        if(dp[m][n]!=-1) return dp[m][n];

        int up = grid[m][n] + solution(m-1,n,grid);
        int down = grid[m][n] + solution(m,n-1,grid);

        dp[m][n] = min(up,down);
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m,vector<int>(n,-1));

        return solution(m-1,n-1,grid);
        
    }
};
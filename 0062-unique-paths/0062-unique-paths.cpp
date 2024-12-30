class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j){

        if(i==0 || j==0){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int up = solve(i-1,j);
        int down = solve(i,j-1);

        return dp[i][j] =  up + down;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1,-1));
        return solve(m-1,n-1);
        
    }
};
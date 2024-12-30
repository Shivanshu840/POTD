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
        dp.resize(m+1,vector<int>(n+1,0));
        // return solve(m-1,n-1);

        for(int i = 0;i<m;i++){
            dp[i][0] = 1;
        }

        for(int j = 0;j<n;j++){
            dp[0][j] = 1;
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){

                int up = dp[i-1][j];
                int down = dp[i][j-1];

                dp[i][j] = up + down;
            }
        }

        return dp[m-1][n-1];
        
    }
};
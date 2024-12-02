class Solution {
public:
    vector<vector<long>>dp;
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
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     dp.resize(m,vector<int>(n,-1));

    //     return solution(m-1,n-1,grid);


            int m = grid.size();
            int n = grid[0].size();
            int ans = 1e9;

            dp.resize(m,vector<long>(n,0));

            dp[0][0] = grid[0][0];
           for(int i=1;i<n;i++){
            dp[0][i]  = dp[0][i-1] + grid[0][i];
           }
           for(int j=1;j<m;j++){
            dp[j][0] = dp[j-1][0] + grid[j][0];
           }


          


            for(int i =1;i<m;i++){

                for(int j = 1;j<n;j++){

                    dp[i][j] = min(grid[i][j]+dp[i-1][j], grid[i][j]+dp[i][j-1]);
                   
                }
            }

            return dp[m-1][n-1];



        
    }
};
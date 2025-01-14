class Solution {
public:
    // Memoized approach for this code
    vector<vector<int>>dp;
    int solve(int x, int y, int row,vector<vector<int>>&matrix){

        if(y>=row || y<0) return INT_MAX;

        if(x==row-1) return matrix[row-1][y];
        if(dp[x][y]!=-1) return dp[x][y];
        int ans = solve(x+1,y-1,row,matrix);
        int ans2 = solve(x+1,y,row,matrix);
        int ans3 = solve(x+1,y+1,row,matrix);

        return dp[x][y] = matrix[x][y] +  min({ans,ans2,ans3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {


        // int res = INT_MAX;
        // int row = matrix.size();

        // dp.resize(row,vector<int>(row,-1));
        
        // for(int i = 0;i<matrix.size();i++){

        //     int ans = solve(0,i,row,matrix);
        //     res = min(ans,res);
        // }

        // return res;



        // This is bottom-up approach

        int row = matrix.size();
        dp.resize(row,vector<int>(row));

        for(int i = 0; i<row;i++){

            dp[0][i] = matrix[0][i];
        }
        

        for(int i = 1;i<row;i++){
            for(int j = 0; j<row;j++){

                /*
                3 case solve karenge 
                a = dp[row-1][col-1];
                b = dp[row-1][col];
                c = dp[row-1][col+1];

                */

                int a = INT_MAX;
                int b = INT_MAX;
                int c = INT_MAX;

                if(i-1>=0 && j-1>=0){

                    a = dp[i-1][j-1];
                }

                if(i-1>=0){

                    b = dp[i-1][j];
                }

                if(i-1>=0 && j+1<row){

                    c = dp[i-1][j+1];
                }


                dp[i][j] = matrix[i][j] + min({a,b,c});
            }
        }


        int lastRow = row-1;
        int ans = INT_MAX;

        for(int i = 0;i<row;i++){
            
            ans = min(ans,dp[lastRow][i]);
        }

        return ans;
    }
};
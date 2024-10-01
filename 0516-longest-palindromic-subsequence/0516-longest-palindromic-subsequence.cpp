class Solution {
public:
    vector<vector<int>>dp;
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        dp.resize(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }


        for(int len = 2; len<=n; len++){
            for(int i=0;i<n-len+1;i++){
                int j = i+len -1;

                if(s[i]==s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};
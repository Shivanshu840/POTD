class Solution {
public:

    vector<vector<int>>dp;

    // it is done by the memoization method


    // int solve(int m, int n, string s1, string s2){
    //     if(m==0 || n==0) return m+n;

    //     if(dp[m][n]!=-1) return dp[m][n];

    //     if(s1[m-1]==s2[n-1]) return dp[m][n] = solve(m-1,n-1,s1,s2);

    //     int insert = 1 + solve(m,n-1,s1,s2);
    //     int del = 1 + solve(m-1,n,s1,s2);
    //     int rep = 1 + solve(m-1,n-1,s1,s2);

    //     return dp[m][n] = min({insert,del,rep});
    // }
    int minDistance(string word1, string word2) {
        
        int len1 = word1.size();
        int len2 = word2.size();
        dp.resize(len1+1,vector<int>(len2+1));
        // return solve(len1,len2,word1,word2); 

        for(int i = 0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                if(i==0 || j==0){
                    dp[i][j] = i + j;
                }
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }

            
            }
        }
       return dp[len1][len2];
    }
};
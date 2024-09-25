class Solution {
public:

    vector<vector<int>>dp;
    int solve(int m, int n, string s1, string s2){
        if(m==0 || n==0) return m+n;

        if(dp[m][n]!=-1) return dp[m][n];

        if(s1[m-1]==s2[n-1]) return dp[m][n] = solve(m-1,n-1,s1,s2);

        int insert = 1 + solve(m,n-1,s1,s2);
        int del = 1 + solve(m-1,n,s1,s2);
        int rep = 1 + solve(m-1,n-1,s1,s2);

        return dp[m][n] = min({insert,del,rep});
    }
    int minDistance(string word1, string word2) {
        
        int len1 = word1.size();
        int len2 = word2.size();
        dp.resize(len1+1,vector<int>(len2+1,-1)); 
        return solve(len1,len2,word1,word2);
    }
};
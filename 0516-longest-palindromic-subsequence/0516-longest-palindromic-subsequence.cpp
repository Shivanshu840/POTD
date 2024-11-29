class Solution {
public:
    vector<vector<int>>dp;
    int longestPalindromeSubseq(string s) {

        // this is 2nd approach reverse the orignal string and then apply the lcs pattern here--> this will be able to solve the palindromic subsequence problem
        string text1 = s;
        reverse(s.begin(),s.end());
        string text2 = s;
        int len1 = text1.size();
        int len2 = text2.size();

        dp.resize(len1+1,vector<int>(len2+1));

        for(int i = 0;i<=len1;i++){

            for(int j = 0; j<=len2; j++){

                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
            }
        }

        for(int i = 1; i<=len1;i++){

            for(int j = 1; j<=len2; j++){

                if(text1[i-1]==text2[j-1]){

                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{

                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[len1][len2];
        
    }
};
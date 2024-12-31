class Solution {
public:
    //brute force for this code
    vector<vector<int>>dp;

    bool checkPalindrome(int i, int j, string s){

       if(i>j) return true;

       if(dp[i][j]!=-1) return dp[i][j];

       if(s[i]==s[j]){
        return dp[i][j] = checkPalindrome(i+1,j-1,s);
       }
       return false;
    }
    int countSubstrings(string s) {
        int n = s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        
        int count = 0;
        for(int i = 0;i<s.size();i++){
            for(int j = i;j<s.size();j++){

                bool ans = checkPalindrome(i,j,s);
                if(ans){
                    count++;
                }
            }
        }


        return count;
    }
};
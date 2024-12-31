class Solution {
public:
    //brute force for this code
    vector<vector<bool>>dp;

    bool checkPalindrome(int i, int j, string s){

       if(i>j) return true;

       if(dp[i][j]!=-1) return dp[i][j];

       if(s[i]==s[j]){
        return dp[i][j] = checkPalindrome(i+1,j-1,s);
       }
       return false;
    }
    int countSubstrings(string s) {
        // int n = s.size();
        // dp.resize(n+1,vector<int>(n+1,-1));
        
        // int count = 0;
        // for(int i = 0;i<s.size();i++){
        //     for(int j = i;j<s.size();j++){

        //         bool ans = checkPalindrome(i,j,s);
        //         if(ans){
        //             count++;
        //         }
        //     }
        // }


        // return count;


        // Bottom up approach for this code

        int n = s.size();
        dp.resize(n+1,vector<bool>(n+1,false));
        int count = 0;


        for(int size = 1; size<=n;size++){

            for(int i = 0;i+size-1<n;i++){

                int j = i+size-1;

                if(i==j){
                    dp[i][j] = true;
                }
                else if(i+1==j){
                    dp[i][j] = (s[i]==s[j]);
                }else{

                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j]==true) count++;
            }

            
        }

        return count;


    }
};
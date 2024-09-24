class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {

        int len1 = s1.size(), len2 = s2.size();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));

        for(int i=1;i<len1+1;i++){
            for(int j=1;j<len2+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] =  max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }


        int i = len1;
        int j = len2;

        string temp = "";

        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                temp.push_back(s1[i-1]);
                i--;
                j--;
            }else if(dp[i-1][j]<dp[i][j-1]){
                temp.push_back(s2[j-1]);
               j--;
            }
            else{

                temp.push_back(s1[i-1]);
                i--;
            }
        }

        while(i>0){
            temp.push_back(s1[i-1]);
            i--;
        }

        while(j>0){
            temp.push_back(s2[j-1]);
            j--;
        }

        reverse(temp.begin(),temp.end());

        return temp;
        
    }
};
class Solution {
public:
    vector<vector<bool>>dp;
    int countSubstrings(string s) {
        string str = s;
        int len = str.size();
        dp.resize(len+1,vector<bool>(len+1,false));
        int count = 0;

        for(int size = 1;size<=len;size++){

        for(int i = 0; i+size-1<len; i++){
            int j = i + size -1;

            if(i==j){           // length 1 wala string hai
                dp[i][j] = true;
            }
            else if(i+1==j){    // length 2 wala string hai ye
                dp[i][j] = (str[i]==str[j]);
            }
            else{  // length 2 se jayda wala string hai
                dp[i][j] = (str[i]==str[j] && dp[i+1][j-1]);
            }

            if(dp[i][j]==true) count++;
        }
    }
    return count;
        
    }
};
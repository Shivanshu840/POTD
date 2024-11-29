class Solution {
public:
    vector<vector<int>>dp;
    int solution(string &s,int i, int j){
        if(i>=j){
        if(i==j) return 1;
         return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){

            return dp[i][j] =  2 + solution(s,i+1,j-1);
        }else{

            return dp[i][j] =  max(solution(s,i+1,j),solution(s,i,j-1));
        }

    }
    int longestPalindromeSubseq(string s) {

        int len = s.size();
        dp.resize(len+1,vector<int>(len+1,-1));


        return solution(s,0,len-1);
        
    }
};
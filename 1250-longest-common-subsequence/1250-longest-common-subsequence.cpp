class Solution {
public:
    vector<vector<int>>dp;
    int solution(string &text1, string &text2, int ind1, int ind2){

        if(ind1>=text1.size() || ind2>=text2.size()){

            return 0;
        }

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(text1[ind1]==text2[ind2]){

            return  dp[ind1][ind2] =  1 + solution(text1,text2, ind1+1, ind2+1);
        }else{

            return dp[ind1][ind2] = max(solution(text1,text2,ind1+1,ind2),solution(text1,text2,ind1,ind2+1));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {

        dp.resize(text1.size()+1,vector<int>(text2.size()+1,-1));

        return solution(text1,text2,0,0);
        
    }
};
class Solution {
public:
    vector<vector<int>>dp;
    // int solution(string &text1, string &text2, int ind1, int ind2){

    //     if(ind1>=text1.size() || ind2>=text2.size()){

    //         return 0;
    //     }

    //     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    //     if(text1[ind1]==text2[ind2]){

    //         return  dp[ind1][ind2] =  1 + solution(text1,text2, ind1+1, ind2+1);
    //     }else{

    //         return dp[ind1][ind2] = max(solution(text1,text2,ind1+1,ind2),solution(text1,text2,ind1,ind2+1));
    //     }

    // }
    int longestCommonSubsequence(string text1, string text2) {

        // dp.resize(text1.size()+1,vector<int>(text2.size()+1,-1));

        // return solution(text1,text2,0,0);

        // ...............................Top Down Approach.........................//

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
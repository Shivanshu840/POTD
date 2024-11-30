class Solution {
public:
    vector<int>dp;
    int solution(int n){

        if(n==0 || n==1){
            return 1;
        }

        if(dp[n]!=-1) return dp[n];
        return dp[n] = solution(n-1) + solution(n-2);
    }
    int climbStairs(int n) {

        dp.resize(n+1,-1);

        return solution(n);
        
    }
};
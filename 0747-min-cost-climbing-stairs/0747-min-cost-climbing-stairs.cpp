class Solution {
public:
    vector<int>dp;
    int solution(vector<int>&cost,int ind){

        if(ind>=cost.size()){
            return 0;
        }

        if(dp[ind]!=-1) return dp[ind];

        return dp[ind] = cost[ind] + min(solution(cost,ind+1), solution(cost,ind+2)); 

    }
    int minCostClimbingStairs(vector<int>& cost) {

        dp.resize(cost.size()+1,-1);
        int ans1 = solution(cost,0);
        int ans2 = solution(cost,1);

        return min(ans1,ans2);
        
    }
};
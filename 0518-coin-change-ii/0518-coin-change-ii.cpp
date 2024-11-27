class Solution {
public:
    vector<vector<int>>dp;
    int solution(vector<int>&coins, int amt, int ind){

        if(ind>=coins.size() || amt ==0){
            if(amt == 0) return 1;

            return 0;
        }

        if(dp[ind][amt]!=-1) return dp[ind][amt];
        if(coins[ind]<=amt){

            int take = solution(coins, amt-coins[ind],ind);
            int notTake = solution(coins,amt,ind+1);
            return dp[ind][amt] = take + notTake;
        }else{

            return dp[ind][amt] = solution(coins,amt,ind+1);
        }
    }
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size()+1,vector<int>(amount+1,-1));
        return solution(coins,amount,0);
        
    }
};
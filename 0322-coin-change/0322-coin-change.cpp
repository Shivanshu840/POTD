class Solution {
public:
    vector<vector<int>>dp;
    int solution(vector<int>& coins, int amnt, int ind) {

        if (ind >= coins.size() || amnt == 0) {

            if (amnt == 0)
                return 0;

            return INT_MAX - 1;
        }

        if(dp[ind][amnt]!=-1) return dp[ind][amnt];

        if (coins[ind] <= amnt) {

            int take = 1 + solution(coins, amnt - coins[ind], ind);
            int notTake = solution(coins, amnt, ind + 1);

            return dp[ind][amnt] =  min(take, notTake);

        } else {
            return dp[ind][amnt] = solution(coins, amnt, ind + 1);
        }
    }
    int coinChange(vector<int>& coins, int amount) {

        dp.resize(coins.size()+1,vector<int>(amount+1,-1));

        int ans = solution(coins, amount, 0);
        if (ans == INT_MAX - 1)
            return -1;

        return ans;
    }
};
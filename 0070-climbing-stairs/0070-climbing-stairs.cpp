class Solution {
public:
    vector<int>dp;
    int rec(int level, int n){
        // solve using the LCCM pattern --> level, choices, check, move

        if(level>n) return 0;  // this is pruning
        if(level == n) return 1; // this is the base case

        if(dp[level]!=-1) return dp[level];

        int ans = 0;

        for(int step = 1; step<=2; step++){ // iterate over all the choices

            if(step+level<=n){  // this is the valid move

                int way = rec(step+level,n); // now move to next level
                ans += way;
            }
        }

        return dp[level] =  ans;
    }
    int climbStairs(int n) {
        dp.resize(n,-1);
        return rec(0,n);
    }
};
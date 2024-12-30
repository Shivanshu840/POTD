class Solution {
public:
// top-down approach
    vector<vector<int>>dp;
    int solve(vector<int>&nums, int prev, int index){

        if(index>=nums.size()) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int take = 0;
        if(prev == -1 || nums[index]>nums[prev]){
            take = 1 + solve(nums,index,index+1);
        }
        int notTake = 0 + solve(nums,prev,index+1);

        return dp[index][prev+1] = max(take,notTake);
    }


    int lengthOfLIS(vector<int>& nums) {

        int prev = -1;
        int index = 0;
        int n = nums.size()+1;
        dp.resize(n+1,vector<int>(n+1,-1));


        return solve(nums,prev,index);
        
    }
};
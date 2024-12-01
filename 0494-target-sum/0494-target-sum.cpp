class Solution {
public:
    vector<vector<int>>dp;
    int solve(int ind,vector<int>&nums,int target){
        if(ind==0){
            if(target==0 && nums[0]==0) return 2;
            if(target == 0 || nums[0]==target) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];

        int exclude = solve(ind-1,nums,target);
        int include = 0;
        if(nums[ind]<=target){
            include = solve(ind-1,nums,target-nums[ind]);
        }

        return dp[ind][target] = exclude + include;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int index = nums.size();
        for(auto itr:nums) sum += itr;

        if((sum-target)<0) return 0;

        if((sum-target)%2==1) return 0;

         int s2 = (sum-target)/2;
        dp.resize(index,vector<int>(s2+1,-1));
        return solve(index-1,nums,s2);
    }
};
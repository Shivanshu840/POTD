class Solution {
public:
    vector<vector<int>>dp;
    int solution(vector<int>&nums, int ind, int prev){

        if(ind>=nums.size()){
            return 0;
        }
        int adj  = prev + 1;

        if(dp[ind][adj]!=-1) return dp[ind][adj];
        
        int take = 0;
        if(prev==-1 || nums[ind]>nums[prev]){
            take = 1 + solution(nums,ind+1,ind);
        }
        int notTake = solution(nums,ind+1,prev);

        return dp[ind][adj] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solution(nums,0,-1);

        
        
    }
};
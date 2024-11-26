class Solution {
public:
    vector<vector<int>>dp;
    bool solution(vector<int>&nums, int target, int ind){
        if(ind>=nums.size() || target==0){
            if(target==0) return true;

            return false;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        if(nums[ind]<=target){
            
            return dp[ind][target] =  solution(nums,target-nums[ind],ind+1) || solution(nums,target,ind+1);
        }else{

            return dp[ind][target] =  solution(nums,target,ind+1);
        }
    }
    bool canPartition(vector<int>& nums) {


        int sum = 0;
        for(auto itr:nums){
            sum += itr;
        }

        if(sum%2==0){

            int target = sum/2;
            dp.resize(nums.size()+1,vector<int>(target+1,-1));

            return solution(nums,target,0);
        }

        return false;
    }
};
class Solution {
public:
    vector<int>dp;
    int solution(vector<int>&nums,int ind){

        if(ind>=nums.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int take =  nums[ind] + solution(nums,ind+2);
        int notTake = 0 + solution(nums,ind+1);

        return dp[ind] = max(take,notTake);

        

        

    }
    int rob(vector<int>& nums) {

        dp.resize(nums.size()+1,-1);


        return solution(nums,0);

        
    }
};
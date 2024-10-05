class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>&nums){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long long maxi = LLONG_MIN;
        for(int ind=i;ind<=j;ind++){
            long long ans = nums[i-1]*nums[ind]*nums[j+1] + solve(i,ind-1,nums)+ solve(ind+1,j,nums);
            maxi = max(maxi,ans);

        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
       int size = nums.size();
       dp.resize(size+1,vector<int>(size+1,-1));
       nums.push_back(1);
       nums.insert(nums.begin(),1);
       

       return solve(1,size,nums);



    }
};
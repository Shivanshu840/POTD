class Solution {
public:

    vector<int>ans;
    set<vector<int>>res;
    void solve(vector<int>&nums, int ind){

        if(ind>= nums.size()){
            return;
        }
        for(int i = 0;i<nums.size();i++){
           swap(nums[i],nums[ind]);
           res.insert(nums);
           solve(nums,ind+1);
           swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        solve(nums,0);
        vector<vector<int>>finalAns(res.begin(),res.end());

        return finalAns;
    }
};
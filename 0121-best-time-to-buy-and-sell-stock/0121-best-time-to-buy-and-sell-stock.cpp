class Solution {
public:
    int maxProfit(vector<int>& nums) {

       int mini = nums[0];
       int profit = 0;

       for(int i=1;i<nums.size();i++){
            int cost = nums[i] - mini;
            profit = max(cost,profit);
            mini = min(nums[i],mini);
       } 

       return profit;
        
    }
};
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxi = 0;
        if(nums.size() == 1) return nums[0];
        for(int i = 1; i<nums.size();i++){

            if(nums[i]>nums[i-1]){

                sum += nums[i];
                maxi = max(sum,maxi);
            }else{
                maxi = max(sum,maxi);
                sum = 0;
                sum += nums[i];
                maxi = max(sum,maxi);
            }
        }

        return maxi;
        
    }
};
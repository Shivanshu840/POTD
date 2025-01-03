class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        long long sum = 0;
        int count = 0;

        for(int i = 0; i<nums.size();i++){
            sum += nums[i];
        }

        long long prefix = 0;

        for(int i = 0;i<nums.size()-1;i++){

            prefix += nums[i];
            long long ans = sum - prefix;
            if(prefix>=ans){
                count++;
            }
        }

        return count;
        
    }
};
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = 0;

        int count = 0;

        for(int i = 1; i<nums.size();i++){

            if(nums[i]>nums[i-1]){

                count++;
               len =  max(count,len);
            }else{
                count = 0;
            }
        }

        count = 0;
        for(int i = 1; i<nums.size();i++){

            if(nums[i]<nums[i-1]){

                count++;
               len =  max(count,len);
            }else{
                count = 0;
            }
        }

        if(len == 0) return 1;
        return len+1;
    }
};
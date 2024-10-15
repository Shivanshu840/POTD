class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int count = 0;
        int zero_count = 0;

        while(j<nums.size()){
            sum += nums[j];

            while(i<j && ( nums[i] == 0 || sum>goal)){
                if(nums[i]==0){
                    zero_count++;
                }else{
                    zero_count = 0;
                }
                sum -= nums[i];
                i++;
            }
            if(sum == goal){
                count += 1 + zero_count; 
            }

            j++;
        }


        return count;
        
    }
};
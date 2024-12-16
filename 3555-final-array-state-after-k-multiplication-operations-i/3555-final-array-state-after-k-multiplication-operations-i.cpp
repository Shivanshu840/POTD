class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        

        for(int i=0;i<k;i++){
            int mini = INT_MAX;
            int index = -1;
            for(int j=0;j<nums.size();j++){
                if(mini>nums[j]){
                    mini = nums[j];
                    index = j;
                }

            }
            cout<<index;
            nums[index] = nums[index]*multiplier;
        }
        return nums;
    }
};
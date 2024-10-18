class Solution {
public:

    int solve(int i, int count,int bitwise,vector<int>&nums){

        if(i>=nums.size()){
            if(bitwise==count) return 1;
            return 0;
        }

    //    if(bitwise==count) return 1;

        // take kar lenge 
        int take = solve(i+1,count,bitwise|nums[i],nums);

        // here is notTaking condition will be apply
        int notTake = 0 +  solve(i+1,count,bitwise,nums);

        return take + notTake;

        

    }
    int countMaxOrSubsets(vector<int>& nums) {
        

        int count = 0;
        for(int i=0;i<nums.size();i++){
            count |= nums[i];
        }

        int bitwise = 0;

        return solve(0,count,bitwise,nums);
    }
};
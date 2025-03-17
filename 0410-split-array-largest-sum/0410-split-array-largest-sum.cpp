class Solution {
public:

    int check(int mid, vector<int>&nums, int k){

        int rem = 0;
        int work = 0;

        for(int i = 0; i<nums.size();i++){

            if(rem>=nums[i]){
                rem  -= nums[i];
            }else{

                work++;
                rem = mid;
                if(work>k) return 0;

                if(rem>=nums[i]){
                    rem -= nums[i];
                }else{
                    return 0;
                }
            }
        }

        return work <= k;
    }
    int splitArray(vector<int>& nums, int k) {

        int sum = 0;
        for(auto itr:nums) sum += itr;
        int ans = 0;
        int s = 1;
        int e = sum;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(check(mid,nums,k)){
                ans = mid;
                e = mid -1;
            }else{
                s = mid + 1;
            }
        }

        return ans;
        
    }
};
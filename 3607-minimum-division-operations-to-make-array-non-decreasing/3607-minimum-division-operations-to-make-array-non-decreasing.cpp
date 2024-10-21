class Solution {
public:

    int smallestPrime(int n){

        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return i;
        }
        return n;
    }
    int minOperations(vector<int>& nums) {

        int count = 0;

        for(int i = nums.size()-2;i>=0;i--){

            if(nums[i]>nums[i+1]){
                count++;
                nums[i] = smallestPrime(nums[i]);
            }

            if(nums[i]>nums[i+1]) return -1;
        }

        return count;
        
    }
};
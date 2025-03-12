class Solution {
public:

    int check(int mid, vector<int>& arr){

        if(mid == arr.size()-1) return 1;

        return arr[mid]>arr[mid+1];
    }
    int findPeakElement(vector<int>& nums) {
        
        int s = 0;
        int e = nums.size()-1;
        int ans = 0;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(check(mid,nums)){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }

        return ans;

        
    }
};
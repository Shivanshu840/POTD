class Solution {
public:
    int check(int mid, vector<int>& nums) {
        return nums[mid] < nums[0];
    }

    int binsrch(vector<int>&nums, int s, int e, int target){

        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid]>target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s = 0;
        int n = nums.size();
        int e = nums.size()-1;
        int pivotIndex = n;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(check(mid,nums)){
                pivotIndex = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        pivotIndex--;
        cout<<pivotIndex<< " "<<endl;

       if(target>=nums[0] && target<=nums[pivotIndex]){

        return binsrch(nums,0,pivotIndex,target);
       }else{

        return binsrch(nums,pivotIndex+1,n-1,target);
       }

        return -1;

    }
};
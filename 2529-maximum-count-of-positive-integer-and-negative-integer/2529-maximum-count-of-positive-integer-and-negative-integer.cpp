class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int n = nums.size();
        auto lb = lower_bound(nums.begin(), nums.end(),0);
        auto ub = upper_bound(nums.begin(), nums.end(),0);

        int l = abs(nums.begin()-lb);
        int u = abs(nums.begin()-ub);
        cout<<l<<" "<<endl;
        int rem = n - u;
        cout<<rem<<" "<<endl;
       

        return max(rem,l);
    }
};
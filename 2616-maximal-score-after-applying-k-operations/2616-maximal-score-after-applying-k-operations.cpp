class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int>q;

        for(auto itr:nums){
            q.push(itr);
        }

        long long int  ans = 0;
        while(k){

            int ele = q.top();
            ans += ele;
             q.pop();

            ele = ceil(ele/3.0);
            q.push(ele);
            k--;


        }

        return ans;

        
    }
};
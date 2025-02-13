class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq(nums.begin(),nums.end());
        
        int count = 0;
        while(pq.top()<k){
            long long int first = pq.top();
            pq.pop();
            long long int second = pq.top();
            pq.pop();
            long long int mini = min(first,second);
            long long int maxi = max(first,second);
            long long int res = 2*mini + maxi;
            pq.push(res);
            count++;
        }
        return count;
    }
};
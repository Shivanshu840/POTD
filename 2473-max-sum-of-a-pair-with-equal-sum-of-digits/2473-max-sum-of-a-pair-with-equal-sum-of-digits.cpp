class Solution {
public:
    int maximumSum(vector<int>& nums) {

        unordered_map<int, priority_queue<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            int temp = nums[i];
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            mp[sum].push(nums[i]);
        }

        int maxi = -1;
        for (auto it : mp) {
            if (it.second.size() >= 2) {
                int first = it.second.top();
                it.second.pop();
                int second = it.second.top();
                maxi = max(maxi, first + second);
            }
        }
        return maxi;
    }
};
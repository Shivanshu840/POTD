class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int mini = INT_MAX;
        long long int sum = 0;
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            sum += nums[j];
            if (sum < target) {
                j++;
            }
            cout << sum << " " << endl;

            if (sum >= target) {
                while (sum >= target) {
                    mini = min(mini, j - i + 1);
                    sum -= nums[i];
                    i++;
                }

                j++;
            }
        }

        return mini == INT_MAX ? 0 : mini;
    }
};
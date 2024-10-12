class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int minStart = INT_MAX;
        int maxEnd = INT_MIN;
        
        for (const auto& d : intervals) {
            minStart = min(minStart, d[0]);
            maxEnd = max(maxEnd, d[1]);
        }

        vector<int> arr(maxEnd + 2, 0);
        int ans = 0;
        for (const auto& d : intervals) {
            arr[d[0]]++;
            arr[d[1] + 1]--;
        }
        int curr = 0;
        for (int i = 0; i < arr.size(); i++) {
            curr += arr[i];
            ans = max(ans, curr);
        }

        return ans;
    }
};
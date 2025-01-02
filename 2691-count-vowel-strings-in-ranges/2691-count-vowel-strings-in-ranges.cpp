class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            string str = words[i];
            int len = str.size();
            if ((str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u') &&
                (str[len - 1] == 'a' || str[len - 1] == 'e' || str[len - 1] == 'i' || str[len - 1] == 'o' || str[len - 1] == 'u')) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        vector<int> ans;
        for (auto& query : queries) {
            int i = query[0];
            int j = query[1];
            ans.push_back(prefixSum[j + 1] - prefixSum[i]);
        }

        return ans;
    }
};

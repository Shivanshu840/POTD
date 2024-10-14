class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;
        map<char, int> mp;

        while (j < s.size()) {
            mp[s[j]]++;

            if(mp.size()>j-i+1){
                j++;
            }

            if (mp.size() < j - i + 1) {

                while (mp.size() < j - i + 1) {
                    mp[s[i]]--;

                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }

                    i++;
                }
            }

            if (mp.size() == j - i + 1) {
                maxi = max(maxi, j - i + 1);
            }

            j++;

        }

        return maxi == INT_MIN ? 0 : maxi;
    }
};
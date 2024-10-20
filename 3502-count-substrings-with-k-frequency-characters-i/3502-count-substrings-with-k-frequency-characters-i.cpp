class Solution {
public:
    int numberOfSubstrings(string s, int k) {

        int i = 0;
        int j = 0;
        map<char, int> mp;
        int count = 0;

        while (j < s.size()) {
            mp[s[j]]++;

            while (mp[s[j]] >= k) {
                count += s.size() - j;
                mp[s[i]]--;
                i++;
            }

            j++;
        }

        return count;
    }
};
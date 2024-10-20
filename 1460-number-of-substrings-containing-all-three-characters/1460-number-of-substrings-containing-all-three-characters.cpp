class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int count = 0;
        map<char, int> mp;

        while (j < s.size()) {
            mp[s[j]]++;  // Add current character to the map

            // When the map contains all 3 characters ('a', 'b', 'c')
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                count += s.size() - j;  // All substrings from i to end of string are valid
                mp[s[i]]--;  // Shrink the window from the left
                i++;  // Move the start pointer
            }

            j++;  // Move the end pointer
        }

        return count;
    }
};

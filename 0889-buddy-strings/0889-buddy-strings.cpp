class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        // Case 1: If s == goal, check for duplicate characters
        if (s == goal) {
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
                if (freq[c - 'a'] > 1) return true;
            }
            return false; // No duplicate characters
        }

        // Case 2: Find the positions where s and goal differ
        vector<int> diff;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                diff.push_back(i);
            }
        }

        // Check if there are exactly two differences and swapping makes them equal
        return (diff.size() == 2 && 
                s[diff[0]] == goal[diff[1]] && 
                s[diff[1]] == goal[diff[0]]);
    }
};

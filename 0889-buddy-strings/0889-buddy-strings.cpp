class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        if (s == goal) {
            unordered_set<char> seen;
            for (char c : s) {
                if (seen.count(c))
                    return true;
                seen.insert(c);
            }
            return false;
        }

        int first = -1, second = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                if (first == -1) {
                    first = i;
                } else if (second == -1) {
                    second = i;
                } else {
                    return false;
                }
            }
        }

        return (second != -1 && s[first] == goal[second] &&
                s[second] == goal[first]);
    }
};

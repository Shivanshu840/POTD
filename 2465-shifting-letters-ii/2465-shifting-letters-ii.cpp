class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int value = (direction == 1) ? 1 : -1;
            diff[start] += value;
            diff[end + 1] -= value;
        }
        vector<int> shiftsApplied(n, 0);
        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += diff[i];
            shiftsApplied[i] = cumulativeShift;
        }
        for (int i = 0; i < n; ++i) {
            int shift = (s[i] - 'a' + shiftsApplied[i]) % 26;
            if (shift < 0) shift += 26; 
            s[i] = 'a' + shift;
        }

        return s;
    }
};
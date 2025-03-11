class Solution {
public:
    int solve(string& s, int k) {
        int n = s.size();
        int tail = 0;
        int head = -1;

        int ans = 0;
        map<char, int> mp;
        int dist = 0;

        while (tail < n) {

            while (head + 1 < n && (dist < k || mp[s[head+1]] >= 1)) {
                head++;

                if(mp[s[head]] == 0){
                    dist++;
                }
                mp[s[head]]++;

              
            }

            ans += head - tail + 1;

            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {

                mp[s[tail]]--;
                if(mp[s[tail]] == 0){
                    dist--;
                }
                tail++;
            }
        }

        return ans;
    }
    int numberOfSubstrings(string s) {
        int k = 3;
        return solve(s,k) - solve(s,k-1);
     }
};
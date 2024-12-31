class Solution {
public:
    vector<int>dp;
    int solve(int i, string s){

        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];

        int result = solve(i+1,s);
        dp[i] = result;
        

        if(i+1<s.size()){

            if(s[i]=='1' || ( s[i] == '2' && s[i+1]<='6')){
                result += solve(i+2,s);
                dp[i] = result;
            }
        }

        return dp[i];

        
    }
    int numDecodings(string s) {
        
        int i = 0;
        int n = s.size();
        dp.resize(n+1,-1);
        return solve(i,s);
    }
};
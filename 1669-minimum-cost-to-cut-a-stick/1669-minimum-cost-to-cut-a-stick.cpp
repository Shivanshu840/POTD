class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, vector<int>&arr){
        if(j-i<2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res = 1e9;
        for(int k=i+1;k<=j-1;k++){

            int ans = (arr[j]-arr[i]) + solve(i,k,arr) + solve(k,j,arr);
            res = min(res,ans);
        }

        return dp[i][j] =  res;
    }
    int minCost(int n, vector<int>& cuts) {
        //pehle sort kardenge cuts ko jisse koi problem nhii hoga cut mein

        sort(cuts.begin(),cuts.end());
        cuts.insert(begin(cuts),0);
        cuts.push_back(n);
        int N = cuts.size();
        dp.resize(N+1,vector<int>(N+1,-1));
        return solve(0,N-1,cuts);
        
    }
};
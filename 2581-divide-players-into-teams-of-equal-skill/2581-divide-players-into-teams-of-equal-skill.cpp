class Solution {
public:
    long long dividePlayers(vector<int>& skills) {

        sort(skills.begin(),skills.end());
        map<pair<int,int>,int>mp;
        int i = 0;
        int j = skills.size()-1;
        int prevSum = 0;
        long long prod = 0;
        while(i<j){
            int currSum = skills[i]+skills[j];
            if(prevSum == 0 || currSum == prevSum){
                prevSum = currSum;
                prod += skills[i++]*skills[j--];
            }else{
                return -1;
            }
        }

        return prod;
        
        // while(i<j){
        //    pair<int,int> pr = {skills[i],skills[j]};
        //    int sum = skills[i++] + skills[j--];
        //    mp[pr] = sum;
        // }
        
        // int res = 0;
        // for(auto itr:mp){
            

        // }

        // return -1;
        
    }
};
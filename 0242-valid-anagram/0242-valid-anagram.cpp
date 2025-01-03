class Solution {
public:
    bool isAnagram(string s, string t) {

        map<char,int>mp;

        if(t.size()>s.size()) return false;


        for(int i = 0;i<s.size();i++){
            mp[s[i]]++;
        }

        for(int i = 0;i<t.size();i++){

            mp[t[i]]--;
        }

        for(auto itr:mp){
            if(itr.second>0) return false;
        }

        return true;
        
    }
};
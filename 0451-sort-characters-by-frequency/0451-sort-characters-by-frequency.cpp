class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        string str = "";

        for(char c:s) mp[c]++;


        for(auto itr:mp){

            pq.push({itr.second,itr.first});
        }

        while(!pq.empty()){
            int n = pq.top().first;
            while(n--) str += pq.top().second;
            
            pq.pop();
        }

        return str;
    }
};
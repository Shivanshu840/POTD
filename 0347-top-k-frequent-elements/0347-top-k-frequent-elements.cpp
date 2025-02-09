class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans;

        for(auto itr:nums) mp[itr]++;

        for(auto itr:mp){

            pq.push({itr.second,itr.first});
            if(pq.size()>k) pq.pop();
        }

        while(!pq.empty()){

            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        



    }
};
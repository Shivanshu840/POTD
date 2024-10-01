class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(auto &val : arr){
            int num = ((val%k) + k)%k;
            m[num]++;
        }
        for(auto &it: m){
            if(it.first != 0){
                int val = it.first;
                int rval = k - val;
                if(val == rval && m[val]&1==1)return false;
                if(m.find(rval)!=m.end()){
                    if(m[val] != m[rval])return false;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
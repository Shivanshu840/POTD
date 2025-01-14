class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        map<int,int>mp;
        vector<int>arr;
        for(int i = 0;i<A.size();i++){

            mp[A[i]]++;
            mp[B[i]]++;
            int count = 0;

            for(auto itr:mp){
                if(itr.second%2==0){
                        count++;

                }
            }

            arr.push_back(count);


        }

        return arr;
    }
};
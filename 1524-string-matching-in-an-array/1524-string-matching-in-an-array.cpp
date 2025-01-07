class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        set<string> ans;
        for(int i = 0;i<words.size();i++){
            string str1 = words[i];
            for(int j = 0;j<words.size();j++){
               string str2 = words[j];

               if(str1==str2){
                continue;
               }else{

                if(str1.find(str2)!= std::string::npos){
                    ans.insert(str2);
                }
               }
            }
        }

        vector<string>result(ans.begin(),ans.end());

        return result;
    }
};
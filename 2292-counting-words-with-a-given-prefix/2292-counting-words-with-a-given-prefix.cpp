class Solution {
public:
    bool isPrefix(string word, string str){

        int n = word.size();
        int m = str.size();
        if(m>n) return false;

        string pre = "";
        vector<string>ans;

        for(int i = 0;i<n;i++){
            pre += word[i];
            ans.push_back(pre);
        }

        for(int i = 0;i<ans.size();i++){

            if(ans[i]==str) return true;
        }

        return false;
    }
    int prefixCount(vector<string>& words, string pref) {

        int count = 0;

        for(int i = 0; i<words.size();i++){

            string str = words[i];

            if(isPrefix(str,pref)){
                count++;
            }
        }
        return count;
    }
};
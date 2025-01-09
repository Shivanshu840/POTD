class Solution {
public:
    bool isPrefix(string word, string str){

        int n = word.size();
        int m = str.size();
        if(m>n) return false;

        string pre = "";

        for(int i = 0;i<n;i++){
            pre += word[i];
            if(pre==str) return true;
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
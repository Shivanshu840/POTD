class Solution {
public:
    string clearDigits(string s) {
        
        string str;

        for(int i = 0; i<s.size();i++){

            if(isalpha(s[i])) str.push_back(s[i]);
            else if(!str.empty()) str.pop_back();
        }

        return str;
    }
};
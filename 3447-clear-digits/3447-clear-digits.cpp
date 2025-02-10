class Solution {
public:
    string clearDigits(string s) {
        
        stack<char>st;
        string str = "";

        for(int i = 0; i<s.size();i++){

            if(isalpha(s[i])) st.push(s[i]);
            else{
                st.pop();
            }
        }

        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }

        reverse(str.begin(),str.end());
        return str;

    }
};
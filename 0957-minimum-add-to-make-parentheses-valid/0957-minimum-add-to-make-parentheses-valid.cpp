class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()){
                if(st.top()=='(' && s[i]==')'){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }
        return st.size();

        
    }
};
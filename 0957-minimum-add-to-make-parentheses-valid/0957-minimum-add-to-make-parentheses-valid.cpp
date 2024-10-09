class Solution {
public:
    int minAddToMakeValid(string s) {

        // stack<char>st;
        // for(int i=0;i<s.size();i++){
        //     if(!st.empty()){
        //         if(st.top()=='(' && s[i]==')'){
        //             st.pop();
        //         }else{
        //             st.push(s[i]);
        //         }
        //     }else{
        //         st.push(s[i]);
        //     }
        // }
        // return st.size();


        int open = 0;
        int close = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }else if(open>0){
                open--;
            }else{
                close++;
            }
        }

        return open + close;

        
    }
};
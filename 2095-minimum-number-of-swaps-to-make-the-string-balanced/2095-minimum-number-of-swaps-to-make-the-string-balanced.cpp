class Solution {
public:
    int minSwaps(string s) {
        // stack<char>st;

        
        // for(int i=0;i<s.size();i++){
        //     if(!st.empty()){
        //     if(st.top()=='[' && s[i]==']'){
        //         st.pop();
        //     }
        //     else{
        //         st.push(s[i]);
        //     }
        //     }else{
        //         st.push(s[i]);
        //     }
        // }

        // if(st.size()==s.size()){
        //     int len = st.size()/2;
        //     return len - 1;
        // }

        // int size = st.size()/2;
        // return size;/

        int left = 0;
        int right = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='['){
                left++;
           
            }else{
                if(left>0){
                    left--;
                }
                else right++;
            }
        }

        return (right + 1)/2;
        


    }
};
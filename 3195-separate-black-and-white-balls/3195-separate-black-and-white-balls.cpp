class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;
        // black ---> 1
        // white --->0
        int zero = 0;

        for(int i=0;i<s.size();i++){
            
            if(s[i]=='1') zero++;
            else count += zero;


        }
        

        return count;
    }
};
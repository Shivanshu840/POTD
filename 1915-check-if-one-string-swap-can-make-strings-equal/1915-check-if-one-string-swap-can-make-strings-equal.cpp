class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        for(int i = 0; i<s2.size();i++){

            for(int j = 0;j<s2.size();j++){

                swap(s2[i],s2[j]);
                if(s1 == s2) return true;
                swap(s2[i],s2[j]);
            }
        }

        return false;
    }
};
class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2) {
        vector<string> pref;
        vector<string> suff;

        string str = "";
        int count = 0;

        // Build prefix vector
        for (int i = 0; i < str2.size(); i++) {
            str += str2[i];
            pref.push_back(str);
        }
        
        str = "";
        // Build suffix vector
        for (int i = str2.size() - 1; i >= 0; i--) {
            str = str2[i] + str; 
            suff.push_back(str);
        }

        
        for (int i = 0; i < pref.size(); i++) {
            if (str1 == pref[i]) {
                count++;
            }
        }

        
        for (int i = 0; i < suff.size(); i++) {
            if (str1 == suff[i]) {
                count++;
            }
        }

        
        return count == 2;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) { // Fixing loop range to include all pairs
                if (i < j && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};

class Solution {
public:
    bool checkPalindrome(int i, int j, string &s) {
        // Check if the string from index i to j is a palindrome
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 0; 
        string temp = ""; 

        // Iterate through all possible substrings of s
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkPalindrome(i, j, s)) {
                    
                    if(j - i + 1 > maxi) {
                        maxi = j - i + 1;
                        temp = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return temp;
    }
};

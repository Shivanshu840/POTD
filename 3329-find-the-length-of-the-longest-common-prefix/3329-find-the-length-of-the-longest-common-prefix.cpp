#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int>mp;
        
  
        for (int num : arr1) {
            string s = to_string(num);
            string str = "";
            for (char ch : s) {
                str += ch;
                mp[str]++;
            }
        }
        
        int maxLength = 0;
        
     
        for (int num : arr2) {
            string s = to_string(num);
            string str = "";
            for (char ch : s) {
                str += ch;
                if (mp.find(str) != mp.end()) {
                    maxLength = max(maxLength, static_cast<int>(str.length()));
                }
            }
        }
        
        return maxLength;
    }
};
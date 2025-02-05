class Solution {
public:
    void NSR(vector<int>& arr, vector<int>& nsr) { 
        stack<pair<int, int>> st;
        int n = arr.size();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= arr[i]) {
                st.pop();
            }
            nsr[i] = (st.empty()) ? n : st.top().second;  
            st.push({arr[i], i});
        }
    }

    void NSL(vector<int>& arr, vector<int>& nsl) { 
        stack<pair<int, int>> st;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first > arr[i]) { 
                st.pop();
            }
            nsl[i] = (st.empty()) ? -1 : st.top().second;  
            st.push({arr[i], i});
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsr(n, n); 
        vector<int> nsl(n, -1); 

        NSR(arr, nsr);
        NSL(arr, nsl);

        long long mod = 1e9 + 7;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - nsl[i];
            long long right = nsr[i] - i;

            sum = (sum + (arr[i] * left * right) % mod) % mod;
        }

        return sum;
    }
};

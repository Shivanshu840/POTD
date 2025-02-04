class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>ans;

        for(int i = 2*n-1;i>=0;i--){

            if(st.empty()) ans.push_back(-1);
            else if(!st.empty() && st.top()>nums[i%n]) ans.push_back(st.top());
            else if(!st.empty() && st.top()<=nums[i%n]){

                while(!st.empty() && st.top()<= nums[i%n]){
                    st.pop();
                }

                if(st.empty()) ans.push_back(-1);
                else ans.push_back(st.top());
            }

            st.push(nums[i%n]);
        }

        reverse(ans.begin(),ans.end());
        vector<int>res(n);

        for(int i = 0; i<n;i++){
            res[i] = ans[i];
        }

        return res;
      

        
        
    }
};
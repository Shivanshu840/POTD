class Solution {
public:

    int findIndx(int target, vector<int>&nums){

        for(int i = 0; i<nums.size();i++){
            if(target == nums[i]) return i;
        }

        return -1;
    }
    void NGR(vector<int>&nsr, vector<int>&nums){

        stack<int>st;

        for(int i = nums.size()-1;i>=0;i--){
            
            if(st.empty()) nsr.push_back(-1);
            else if(!st.empty() && st.top()>nums[i]) nsr.push_back(st.top());
            else if(!st.empty() && st.top()<=nums[i]){

                while(!st.empty() && st.top()<=nums[i]){
                    st.pop();
                }

                if(st.empty()) nsr.push_back(-1);
                else nsr.push_back(st.top());
            }

            st.push(nums[i]);
        }

        reverse(nsr.begin(),nsr.end());
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int>nsr;
        NGR(nsr,nums2);
        vector<int>res;

        for(int i = 0; i<nums1.size();i++){

            int indx = findIndx(nums1[i],nums2);
            res.push_back(nsr[indx]);
        }

        return res;


        
    }
};
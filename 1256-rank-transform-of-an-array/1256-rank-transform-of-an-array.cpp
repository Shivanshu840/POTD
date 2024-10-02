class Solution {
public:
    int search(int ele,vector<int>&arr){
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid]==ele){
                return mid+1;
            }else if(arr[mid]>ele){
                e = mid -1;
            }else{
                s = mid + 1;
            }

            mid = s + (e-s)/2;
        }

        return -1;
    }
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st(arr.begin(),arr.end());
        vector<int>temp(st.begin(),st.end());
        for(int i=0;i<arr.size();i++){
            arr[i] = search(arr[i],temp);
           

        }

        return arr;
    }
};
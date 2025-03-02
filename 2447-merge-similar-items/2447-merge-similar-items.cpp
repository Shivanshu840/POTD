class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
         

         sort(nums1.begin(),nums1.end());
         sort(nums2.begin(),nums2.end());
        int i = 0;
        int j = 0;
        vector<vector<int>>res;
        while(i<nums1.size() && j<nums2.size()){

            int id1 = nums1[i][0];
            int val1 = nums1[i][1];

            int id2 = nums2[j][0];
            int val2 = nums2[j][1];

            if(id1 == id2){
                res.push_back({id1, val1 + val2});
                i++;
                j++;
            }else if(id1<id2){
                res.push_back({id1,val1});
                i++;
            }else{

                res.push_back({id2,val2});
                j++;
            }
        }

        while(i<nums1.size()){
            int id = nums1[i][0];
            int val = nums1[i][1];
            res.push_back({id,val});
            i++;
        }

         while(j<nums2.size()){
            int id = nums2[j][0];
            int val = nums2[j][1];
            res.push_back({id,val});
            j++;
        }

        return res;
        
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // we can solve it using the priority_queue

        priority_queue<int,vector<int>,greater<int>>pq;

        //pehle first k element ko insert kar denge esse space complexity kam ho jayega esliye
        // min heap liye hai

        for(int i = 0;i<k;i++){
            pq.push(nums[i]);
        }

        // fir usii element ko push karenge joo top element se largest hoga

        for(int i = k; i<nums.size();i++){

            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();

        
        
    }
};
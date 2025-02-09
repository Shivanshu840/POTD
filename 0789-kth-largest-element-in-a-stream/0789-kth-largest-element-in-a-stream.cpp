class KthLargest {
public:

    int k;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        
        this->k = k;
        for(int i = 0;i<nums.size();i++){

             add(nums[i]);
        }
    }
    
    int add(int val) {
        
        if(pq.size()<k || val>pq.top()){

            pq.push(val);
        }

        if(pq.size()>k) pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int>pq(gifts.begin(),gifts.end());

        for(int i = 0; i<k;i++){
            int top = pq.top();
            pq.pop();

            top = floor(sqrt(top));
            pq.push(top);

            
        }

        long long sum = 0;

        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            sum += top;
        }
        
        return sum;
    }
};
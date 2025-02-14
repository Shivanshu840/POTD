class ProductOfNumbers {
public:
    vector<int>pq;
    int k;
    int product;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        pq.push_back(num);
    }
    
    int getProduct(int k) {
      
        if(pq.size()<k) return 0;
        int product =1;

        for(int i = pq.size()-k;i<pq.size();i++){

            product *= pq[i];
        }

        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
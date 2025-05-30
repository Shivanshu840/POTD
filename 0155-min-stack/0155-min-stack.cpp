class MinStack {
public:
    vector<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(st.empty()){
            st.push_back({val,val});
        }else{
            int it = st.back().second;
            int mini = min(it,val);
            st.push_back({val,mini});
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        int topEle = st.back().first;
        return topEle;
    }
    
    int getMin() {
        int mini = st.back().second;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
public:
    // {curr,minTillNow}
    stack<pair<int,int>>st;
    
    MinStack() {
        
    }
    
    void push(int value) {
        int sec=st.empty()?value:min(value,st.top().second);
        st.push({value,sec});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
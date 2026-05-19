class MinStack {
public:
    long long mini=1e18;
    stack<long long>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else{
            if(val>=mini) st.push(val);
            else{
                long long newVal=(long long)2*val-mini;
                mini=val;
                st.push(newVal);
            }
        }
    }
    
    void pop() {
        if(st.top()>=mini) st.pop();
        else{
            // newVal=2*val-prevMini
            int prevMini=2*mini-st.top();
            mini=prevMini;
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>=mini) return st.top();
        else return mini;
    }
    
    int getMin() {
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
class MinStack {
private: 
    list<pair<int,int>> l;
    int min;
public:
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        if(l.empty() || val<l.front().second) {
            l.push_front({val,val});
            return;
        }
        l.push_front({val,l.front().second});
    }
    
    void pop() {
        if(l.empty()) return;
        l.pop_front();
        return;
    }
    
    int top() {
        return l.empty() ? -1 : l.front().first;
    }
    
    int getMin() {
        return l.front().second;
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

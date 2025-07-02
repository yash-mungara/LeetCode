class MinStack {
public:
    stack<long long int> s;
    long long int min;   
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){s.push(val);
        min = val;
        } else{
            if(val < min){
                s.push((long long)2*val - min);
                min = val;
            }
            else s.push(val);
        }
    
    }
    
    void pop() {
        if(s.top()<min){
            min = 2*min - s.top();
            
        }
        s.pop();
    }
    
    int top() {
        if(s.top()<min) return min;
        else return s.top();
    }
    
    int getMin() {
        return min;
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

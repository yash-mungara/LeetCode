class MyStack {
public:
    
    queue<int> mystack;
    MyStack() {
    }
    
    void push(int x) {
        mystack.push(x);
        for(int i=1;i<mystack.size();i++){
            mystack.push(mystack.front());
            mystack.pop();
        }
    }
    
    int pop() {
        int temp = mystack.front();
        mystack.pop();
        return temp;
    }
    
    int top() {
        return mystack.front();
    }
    
    bool empty() {
        return mystack.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

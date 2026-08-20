class MinStack {
    stack<int> OriginalStack;
    stack<int> AuxStack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        OriginalStack.push(value);
        if (AuxStack.empty() || value < AuxStack.top()){
            AuxStack.push(value);
        }
        else AuxStack.push(AuxStack.top());
    }
    
    void pop() {
        if (!OriginalStack.empty()){
            OriginalStack.pop();
            AuxStack.pop();
        }
    }
    
    int top() {
        return OriginalStack.top();
    }
    
    int getMin() {
        return AuxStack.top();
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
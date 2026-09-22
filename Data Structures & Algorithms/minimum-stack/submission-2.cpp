class MinStack {
private:
    stack<int> mainStack;
    stack<int> minTracker;
public:
    MinStack() {
        mainStack = {};
        minTracker = {};
    }
    
    void push(int val) {
        mainStack.push(val);
        if (minTracker.empty()) {
            minTracker.push(val);
        } else {
            minTracker.push(min(val, minTracker.top()));
        }
    }
    
    void pop() {
        mainStack.pop();
        minTracker.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minTracker.top();
    }
};

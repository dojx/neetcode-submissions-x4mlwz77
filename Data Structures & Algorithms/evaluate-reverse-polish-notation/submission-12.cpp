class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        int a, b;

        for (const string& t : tokens) {
            if (t == "+") {
                b = operands.top();
                operands.pop();
                a = operands.top();
                operands.pop();
                operands.push(a + b);
            } else if (t == "-") {
                b = operands.top();
                operands.pop();
                a = operands.top();
                operands.pop();
                operands.push(a - b);
            } else if (t == "*") {
                b = operands.top();
                operands.pop();
                a = operands.top();
                operands.pop();
                operands.push(a * b);
            } else if (t == "/") {
                b = operands.top();
                operands.pop();
                a = operands.top();
                operands.pop();
                operands.push(a / b);
            } else {
                operands.push(stoi(t));
            }
        }

        return operands.top();
    }
};

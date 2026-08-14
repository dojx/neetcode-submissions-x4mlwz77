class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for (const string& t : tokens) {
            if (t == "+") {
                int b = operands.top(); operands.pop();
                int a = operands.top(); operands.pop();
                operands.push(a + b);
            }
            else if (t == "-") {
                int b = operands.top(); operands.pop();
                int a = operands.top(); operands.pop();
                operands.push(a - b);
            }
            else if (t == "*") {
                int b = operands.top(); operands.pop();
                int a = operands.top(); operands.pop();
                operands.push(a * b);
            }
            else if (t == "/") {
                int b = operands.top(); operands.pop();
                int a = operands.top(); operands.pop();
                operands.push(a / b);
            }
            else {
                operands.push(stoi(t));
            }
        }

        return operands.top();
    }
};
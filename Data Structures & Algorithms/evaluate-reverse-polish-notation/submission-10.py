'''
    stack: contains operands
    iterate through array
    if operator found:
        pop last 2 operands and perform operation
        push result to stack

    final result will be only element in stack
'''

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for t in tokens:
            if t == '+':
                b = stack.pop()
                a = stack.pop()
                stack.append(a + b)
            elif t == '-':
                b = stack.pop()
                a = stack.pop()
                stack.append(a - b)
            elif t == '*':
                b = stack.pop()
                a = stack.pop()
                stack.append(a * b)
            elif t == '/':
                b = stack.pop()
                a = stack.pop()
                stack.append(int(a / b))
            else:
                stack.append(int(t))

        return stack[0]
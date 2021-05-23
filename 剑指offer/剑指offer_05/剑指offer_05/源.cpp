/*
* 用两个栈模拟一个队列
* 思路简单，push的时候先存进一个栈，pop的时候再按顺序将所有元素放进另一个栈，然后pop。需要注意的是，pop时，若第二个栈不为空，
*则不可以往里面push，否则顺序会乱
*/



class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
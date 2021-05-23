/*
* ������ջģ��һ������
* ˼·�򵥣�push��ʱ���ȴ��һ��ջ��pop��ʱ���ٰ�˳������Ԫ�طŽ���һ��ջ��Ȼ��pop����Ҫע����ǣ�popʱ�����ڶ���ջ��Ϊ�գ�
*�򲻿���������push������˳�����
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
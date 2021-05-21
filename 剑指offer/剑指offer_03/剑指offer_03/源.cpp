#include<iostream>
#include<vector>
using namespace std;

//第一步想到的解法，十分简单，便历链表，push到vector当中，再调用std::reverse翻转顺序即可
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> ret;
    while (head) {
        ret.push_back(head->val);
        head = head->next;
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}

//第2种解法，使用递归的思路，注意，操作的顺序已经决定了他是倒序了
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int>res;
    if (head == NULL)
    {
        return res;
    }

    res = printListFromTailToHead(head->next);
    res.push_back(head->val);
    return res;
}

//第3种解法，参考网友的链表翻转，以前并没有接触过。结合注释，需要三个结点实现链表反转
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int>res;
    ListNode* pre = NULL;//前一个结点，初始为空，因为头结点反转之后的next为空
    ListNode* cur = head;//正在反转的结点
    ListNode* temp = cur;//还未反转的第一个结点，不然断开之后就无法找到下一个结点了
    while (cur)
    {
        temp = cur->next;//保存还未反转的第一个结点，准备下一步断开
        cur->next = pre;//当前结点指向下一个结点断开，连接到上一个结点
        pre = cur;//各自往右进一步，直到整个链表反转完成
        cur = temp;
    }
    vector<int> ret;
    while (pre) {
        ret.push_back(pre->val);
        pre = pre->next;
    }
    return ret;
}
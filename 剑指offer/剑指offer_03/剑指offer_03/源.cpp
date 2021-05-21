#include<iostream>
#include<vector>
using namespace std;

//��һ���뵽�Ľⷨ��ʮ�ּ򵥣���������push��vector���У��ٵ���std::reverse��ת˳�򼴿�
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> ret;
    while (head) {
        ret.push_back(head->val);
        head = head->next;
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}

//��2�ֽⷨ��ʹ�õݹ��˼·��ע�⣬������˳���Ѿ����������ǵ�����
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

//��3�ֽⷨ���ο����ѵ�����ת����ǰ��û�нӴ��������ע�ͣ���Ҫ�������ʵ������ת
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int>res;
    ListNode* pre = NULL;//ǰһ����㣬��ʼΪ�գ���Ϊͷ��㷴ת֮���nextΪ��
    ListNode* cur = head;//���ڷ�ת�Ľ��
    ListNode* temp = cur;//��δ��ת�ĵ�һ����㣬��Ȼ�Ͽ�֮����޷��ҵ���һ�������
    while (cur)
    {
        temp = cur->next;//���滹δ��ת�ĵ�һ����㣬׼����һ���Ͽ�
        cur->next = pre;//��ǰ���ָ����һ�����Ͽ������ӵ���һ�����
        pre = cur;//�������ҽ�һ����ֱ����������ת���
        cur = temp;
    }
    vector<int> ret;
    while (pre) {
        ret.push_back(pre->val);
        pre = pre->next;
    }
    return ret;
}
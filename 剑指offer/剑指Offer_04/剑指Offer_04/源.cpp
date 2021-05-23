/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



/*
* �ݹ��˼·���ǰ������õ����������������⡣
* ���ȷ�����ǰ��ĵ�һ����ȻΪ�����Ѹ��ҳ�����Ȼ�����������ҵ��������λ�á���ô��������������У���ǰ��Ķ�����������������Ķ���
* �������ϵģ��ٸ���������ǰ��������зָ���������Ǿ͵õ����ĸ�Сһ������������ֱ�����������ǰ����������������
*��������ǰ�����������������ݹ�ֱ��û�н��Ϊֹ��������ɡ�
*/






class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (vin.size() == 0 || pre.size() == 0)
        {
            return NULL;
        }
        int _root = pre[0];//ǰ������ĵ�һ�����϶�Ϊ��
        TreeNode* head = new TreeNode(_root);
        int _num = 0;//�����������������е�λ��
        for (int i = 0; i < vin.size(); i++)
        {
            if (_root == vin[i])
            {
                _num = i;
                break;
            }
        }
        vector<int>NewPreLeft;
        vector<int>NewPreRight;
        vector<int>NewVinLeft;
        vector<int>NewVinRight;
        for (int i = 0; i < _num; i++)
        {
            NewPreLeft.push_back(pre[i + 1]);
            NewVinLeft.push_back(vin[i]);
        }
        for (int i = _num + 1; i < vin.size(); i++)
        {
            NewVinRight.push_back(vin[i]);
            NewPreRight.push_back(pre[i]);
        }
        head->left = reConstructBinaryTree(NewPreLeft, NewVinLeft);
        head->right = reConstructBinaryTree(NewPreRight, NewVinRight);
        return head;
    }
};
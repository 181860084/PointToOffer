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
* 递归的思路解决前序中序得到完整二叉树的问题。
* 首先分析，前序的第一个必然为根，把根找出来，然后在中序当中找到这个根的位置。那么，在中序遍历当中，根前面的都是左子树，根后面的都是
* 右子树上的，再根绝个数对前序遍历进行分割，这样，我们就得到了四个小一点的序列数。分别是左子树的前序遍历，中序遍历；
*右子树的前序遍历，中序遍历，递归直到没有结点为止，程序完成。
*/






class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (vin.size() == 0 || pre.size() == 0)
        {
            return NULL;
        }
        int _root = pre[0];//前序遍历的第一个结点肯定为根
        TreeNode* head = new TreeNode(_root);
        int _num = 0;//根结点在中序遍历当中的位次
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
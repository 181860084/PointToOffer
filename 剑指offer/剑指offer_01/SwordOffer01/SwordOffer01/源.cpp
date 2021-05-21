#include<iostream>
#include<vector>

using namespace std;

/*
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int line = array.size();//��ά��������
        int col = array[0].size();//��ά��������
        int i = 0;
        for (; i < line; i++)
        {
            int j = 0;
            for (; j < col; j++)
            {
                if (array[i][j] < target);
                else if (array[i][j] == target)
                {
                    return true;
                }
                else if (array[i][j] > target)
                {
                    col = j;
                    break;
                }
            }
        }
        return false;
    }
};*/

/*ע�ͣ�
����ע�⵽������ȷʵ����ͨ����������������մ𰸣�����ʱ�临�Ӷ�̫���ˡ��ҵ�˼·���������0��ʼ���±���������ͨ����С��ϵ�����ж�
��������ϵ͵�һά�����е�ĳ�ж��Ѿ�����target��ֵ����ô��һ�дӸ��п�ʼ�Ͳ����ٱȽ��ˣ��൱�ڲ���ѹ���еĴ�С�������Ӷ�ѹ��
*/

/*
�ðɣ���ס�ˣ���׼���Ƕ��ֲ��ң��ȶ������ѹ��ʱ�临�Ӷȡ�
�򵥵����룺�������鵱�в���һ����-------���ֲ��ҡ�
�����������һ�����֣����Լ��ĳ���˼·��Ȼ�����д������µ�����һ����ʹ�õķǳ�����֣����ԣ����þ����ڴ������ҡ��������µ�˳������
ֱ�Ӵ������Ͻǿ�ʼ��ÿһ���ų�һ�л���һ�У�ʱ�临�Ӷ�ΪO(m+n)
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int line = array.size();//��ά��������
        int col = array[0].size();//��ά��������
        int l = 0;
        int r = col - 1;
        int i = l;
        while (r >= 0 && l < line)
        {
            int i = l;
            int j = r;
            if (array[i][j] < target)
            {
                l++;
            }
            else if (target == array[i][j])
            {
                return true;
            }
            else
            {
                r--;
            }
        }

        return false;
    }
};
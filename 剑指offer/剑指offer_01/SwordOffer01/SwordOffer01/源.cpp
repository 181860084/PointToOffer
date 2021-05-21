#include<iostream>
#include<vector>

using namespace std;

/*
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int line = array.size();//二维数组行数
        int col = array[0].size();//二维数组列数
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

/*注释：
不难注意到，本题确实可以通过暴力穷举做出最终答案，但是时间复杂度太高了。我的思路是行上面从0开始往下遍历，而列通过大小关系不难判断
如果行数较低的一维数组中的某列都已经大于target数值，那么下一行从该列开始就不必再比较了，相当于不断压缩列的大小，将复杂度压缩
*/

/*
好吧，尬住了，标准答案是二分查找，稳定大幅度压缩时间复杂度。
简单的联想：有序数组当中查找一个数-------二分查找。
不过这道题是一个变种，我自己的初次思路显然对于列从上往下递增这一条件使用的非常不充分，所以，不用拘泥于从左往右、从上往下的顺序来找
直接从最右上角开始，每一次排除一行或者一列，时间复杂度为O(m+n)
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int line = array.size();//二维数组行数
        int col = array[0].size();//二维数组列数
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
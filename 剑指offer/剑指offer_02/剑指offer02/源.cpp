#include<iostream>
#include<string>

using namespace std;

string replaceSpace(string s) {
    int N = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            N++;
    }
    // write code here
    for (int i = 0; i < N; i++)
    {
        cout << s.find(' ');
        s = s.replace(s.find(' '), 1, "%20");

    }
    return s;
}

int main()
{
    string s="asfd adsf 666";
    //cout << s;
    cout << replaceSpace(s);
    return 0;
}

/*
* 算法上并没有什么新思路，主要是熟悉了string当中通过find()方法和replace()方法结合实现字符串快速替换的算法
*/
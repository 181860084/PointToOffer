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
* �㷨�ϲ�û��ʲô��˼·����Ҫ����Ϥ��string����ͨ��find()������replace()�������ʵ���ַ��������滻���㷨
*/
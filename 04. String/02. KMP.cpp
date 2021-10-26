// KMP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

void GetNext(vector<size_t>& next, string str)
{
    size_t i = 1;
    size_t j = 0;
    next[1] = 0;
    while (i < str.size())
    {
        if (j == 0 || str[j - 1] == str[i - 1])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];//回退
        }
    }
}

int KMP(string src, string dis) 
{
    vector<size_t>next(20, 0);
    size_t i = 1;
    size_t j = 1;
    GetNext(next, dis);
    while (i <= src.size() && j <= dis.size())
    {
        if (j == 0 || src[i - 1] == dis[j - 1])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (j > dis.size())
    {
        return (int)(i - dis.size());
    }

    return -1;
}

int main()
{
    cout << KMP("ababcabcacbab", "abcac") << endl;
    return 0;
}

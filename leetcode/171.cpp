//LeetCode 171. Excel Sheet Column Number
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int num = 0;
        for(char ch : columnTitle)
        {
            num = num * 26 + (ch - 'A' + 1);
        }
        return num;
    }
};
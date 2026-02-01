//Q14
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 1)
            return strs[0];
        int minLength = INT_MAX;
        for (int i = 0; i < strs.size(); i++)
        {
            minLength = min(minLength, (int)strs[i].length());
        }
        if (minLength == 0)
            return "";
        for (int i = 0; i < minLength; i++)
        {
            char currentChar = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != currentChar)
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0].substr(0, minLength);
    }
};
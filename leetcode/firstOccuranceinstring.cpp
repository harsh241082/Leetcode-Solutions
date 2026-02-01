//Q28
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int H = haystack.size();
        int N = needle.size();
        if (N == 0)
            return 0;

        for (int i = 0; i <= H - N; i++)
        {
            int j = 0;
            while (j < N && haystack[i + j] == needle[j])
            {
                j++;
            }
            if (j == N)
                return i;
        }
        return -1;
    }
};
//using predefined function
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = needle.length();
        int h = haystack.length();

        if (n == 0)
            return 0;

        for (int i = 0; i <= h - n; i++)
        {
            if (haystack.substr(i, n) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};

//Leetcode 1668 : Maximum Repeating Substring
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxRepeating(string s, string w)
    {
        int rep = 0;
        int n = s.length();
        int l = w.length();

        for (int i = 0; i <= n - l; i++)
        {
            int count = 0;
            int j = i;
            while (j + l <= n && s.substr(j, l) == w)
            {
                count++;
                j += l;
            }
            rep = max(rep, count);
        }

        return rep;
    }
};

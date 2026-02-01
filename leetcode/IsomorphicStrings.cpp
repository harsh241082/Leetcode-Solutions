// Leetcode 205. Isomorphic Strings
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        vector<int> map_s_to_t(256, -1);
        vector<int> map_t_to_s(256, -1);

        for (int i = 0; i < s.size(); i++)
        {
            char c1 = s[i], c2 = t[i];

            if (map_s_to_t[c1] == -1 && map_t_to_s[c2] == -1)
            {
                map_s_to_t[c1] = c2;
                map_t_to_s[c2] = c1;
            }
            else
            {
                if (map_s_to_t[c1] != c2 || map_t_to_s[c2] != c1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

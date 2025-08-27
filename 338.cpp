//Leetcode 338 : Counting Bits
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        ans[0] = 0;
        if (n == 0)
            return ans;
        ans[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            ans[i] = ans[i >> 1] + (i & 1);  // right shift by 1 so that we can get the previous value and add 1 if the last bit is 1
        }
        return ans;
    }
};
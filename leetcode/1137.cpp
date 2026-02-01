//Leetcode 1137 : N-th Tribonacci Number
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }

    int tribonacci2(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int a = 0;
        int b = 1;
        int c = 1;
        int d;
        for (int i = 3; i <= n; i++)
        {
            d = c + b + a;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};
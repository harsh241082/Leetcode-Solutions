//Leetcode 509 : Fibonacci Number
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int fib2(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int a = 0;
        int b = 1;
        int c;
        for (int i = 2; i <= n; i++)
        {
            c = b + a;
            a = b;
            b = c;
        }
        return c;
    }
};
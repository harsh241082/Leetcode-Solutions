// LeetCode Problem 8 : String to Integer

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.length();
        int result = 0;
        bool isNegative = false;
        // Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;
        // Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            isNegative = (s[i] == '-');
            i++;
        }
        // Convert characters to integer
        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';
            // Check for overflow/underflow
            if (result > (INT_MAX - digit) / 10)
                return isNegative ? INT_MIN : INT_MAX;
            result = result * 10 + digit;
            i++;
        }
        return isNegative ? -result : result;
    }
};
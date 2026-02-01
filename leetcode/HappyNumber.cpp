//Q202
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumofsquares(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<int> found;
        while (n != 1)
        {
            n = sumofsquares(n);
            if (found.find(n) != found.end())
            {
                return false;
            }
            else
            {
                found.insert(n);
            }
        }
        return true;
    }
};
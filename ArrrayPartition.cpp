//leetcode 561. Array Partition I
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i = i + 2)
        {
            sum += nums[i];
        }
        return sum;
    }
};
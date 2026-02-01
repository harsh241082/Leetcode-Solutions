//leetcode 1920 Build Array from Permutation
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(nums[nums[i]]);
        }
        return result;
    }
};

//O(n) time and O(1) space
class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i] += (nums[nums[i]]) * n;
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] /= n;
        }
        return nums;
    }
};
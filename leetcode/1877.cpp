// leetcode 1877. Minimize Maximum Pair Sum in Array
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = n - 1;
        int maxSum = 0;

        while (left < right)
        {
            int pairSum = nums[left] + nums[right];
            maxSum = max(maxSum, pairSum);
            left++;
            right--;
        }
        return maxSum;
    }
};
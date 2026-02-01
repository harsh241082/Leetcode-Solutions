//Q209
//Minimum Size Subarray Sum
#include<bits/stdc++.h>
using namespace std;

//Binary Search Approach
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = nums[i]+  prefixSum[i - 1];
        }
        if(prefixSum[n - 1] < target)
            return 0; 
        int minLength = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (prefixSum[i] >= target)
            {
                int left = 0, right = i;
                while (left <= right)
                {
                    int mid = left + (right - left) / 2;
                    if (prefixSum[i] - (mid > 0 ? prefixSum[mid - 1] : 0) >= target)
                    {
                        minLength = min(minLength, i - mid + 1);
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};

//Sliding Window Approach
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, sum = 0, minLen = INT_MAX;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

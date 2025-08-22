//leetcode 228. Summary Ranges
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ranges;
        int n = nums.size();
        if (n == 0)
            return ranges;

        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1 || nums[i + 1] != nums[i] + 1)
            {
                if (start == i)
                {
                    ranges.push_back(to_string(nums[start]));
                }
                else
                {
                    ranges.push_back(to_string(nums[start]) + "->" +
                                     to_string(nums[i]));
                }
                start = i + 1;
            }
        }
        return ranges;
    }
};

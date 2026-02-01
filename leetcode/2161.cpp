//Leetcode 2161. Partition Array According to Given Pivot
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot) //brute force = O(3n)
    {
        vector<int> temp;
        temp.reserve(nums.size());
        for (int n : nums)
        {
            if (n < pivot)
            {
                temp.push_back(n);
            }
        }
        for (int n : nums)
        {
            if (n == pivot)
            {
                temp.push_back(n);
            }
        }
        for (int n : nums)
        {
            if (n > pivot)
            {
                temp.push_back(n);
            }
        }
        return temp;
    }

    vector<int> pivotArray2(vector<int> &nums, int pivot)   //two pointer approach = O(n)
    {
        vector<int> result(nums.size(), 0);
        int left = 0, right = nums.size() - 1;

        for (int i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j)
        {
            if (nums[i] < pivot)
            {
                result[left] = nums[i];
                left++;
            }

            if (nums[j] > pivot)
            {
                result[right] = nums[j];
                right--;
            }
        }

        while (left <= right)
        {
            result[left] = pivot;
            left++;
        }

        return result;
    }
};
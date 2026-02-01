// LeetCode 493 : Reverse Pairs
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return 0;
        }
        int count = 0;
        int mid = left + (right - left) / 2;
        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        count += merge(nums, left, mid, right);
        return count;
    }
    int merge(vector<int> &nums, int left, int mid, int right)
    {
        int count = 0;
        int j = mid + 1;
        for (int i = left; i <= mid; i++)
        {
            while (j <= right && (long)nums[i] > 2 * (long)nums[j])
            {
                j++;
            }
            count += (j - (mid + 1));
        }

        vector<int> temp(right - left + 1);
        int i = left;
        j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid)
        {
            temp[k++] = nums[i++];
        }

        while (j <= right)
        {
            temp[k++] = nums[j++];
        }

        for (int p = 0; p < temp.size(); p++)
        {
            nums[left + p] = temp[p];
        }

        return count;
    }
};
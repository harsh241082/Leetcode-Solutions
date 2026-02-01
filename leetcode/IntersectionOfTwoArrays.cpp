//leetcode 349 Intersection of Two Arrays
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> inter;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else
            {
                if (inter.size() == 0 || inter.back() != nums1[i])
                {
                    inter.push_back(nums1[i]);
                }
                i++, j++;
            }
        }
        return inter;
    }
};
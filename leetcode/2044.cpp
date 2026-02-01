#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        vector<vector<int>> subs = subsetsWithDup(nums);
        int maxOR = 0, count = 0;
        for (auto &sub : subs)
        {
            int currOR = 0;
            for (int n : sub)
            {
                currOR |= n;
            }
            if (currOR > maxOR)
            {
                maxOR = currOR;
                count = 1;
            }
            else if (currOR == maxOR)
            {
                count++;
            }
        }
        return count;
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums, 0, subset, result);
        return result;
    }

private:
    void backtrack(vector<int> &nums, int index, vector<int> &subset,vector<vector<int>> &result)
    {

        result.push_back(subset);

        for (int i = index; i < (int)nums.size(); i++)
        {
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
};
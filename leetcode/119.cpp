//leetcode 119 Pascal's Triangle II
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        int n = rowIndex + 1;
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }

            res.push_back(row);
        }
        return res[n - 1];
    }
};
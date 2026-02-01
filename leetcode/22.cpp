// Leetcode 22: Generate Parentheses
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void backtrack(vector<string> &res, string &current, int open, int close, int max)
    {
        if (current.length() == max * 2)
        {
            res.push_back(current);
            return;
        }
        if (open < max)
        {
            current.push_back('(');
            backtrack(res, current, open + 1, close, max);
            current.pop_back();
        }
        if (close < open)
        {
            current.push_back(')');
            backtrack(res, current, open, close + 1, max);
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string current;
        backtrack(res, current, 0, 0, n);
        return res;
    }
};


int main()
{
    Solution sol;
    int n = 3; // Example input
    vector<string> result = sol.generateParenthesis(n);
    for (const string &s : result)
    {
        cout << s << endl;
    }
    return 0;
}
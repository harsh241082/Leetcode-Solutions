//LeetCode 17. Letter Combinations of a Phone Number
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void backtrack(int index, string &current, const string &digits, const vector<vector<char>> &mappings, vector<string> &result)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }
        int digit = digits[index] - '2';
        for (char c : mappings[digit])
        {
            current.push_back(c);
            backtrack(index + 1, current, digits, mappings, result);
            current.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits)
    {
        vector<vector<char>> mappings(8);
        mappings[0] = {'a', 'b', 'c'};      
        mappings[1] = {'d', 'e', 'f'};      
        mappings[2] = {'g', 'h', 'i'};      
        mappings[3] = {'j', 'k', 'l'};      
        mappings[4] = {'m', 'n', 'o'}; 
        mappings[5] = {'p', 'q', 'r', 's'}; 
        mappings[6] = {'t', 'u', 'v'};     
        vector<string> result;
        if (digits.empty())
            return result;
        
        string current;
        backtrack(0, current, digits, mappings, result);
        return result;
    }
};
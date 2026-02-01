// LeetCode 2942 : Find words containing the character

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    vector<int> findWords(vector<string> &words, char ch)
    {
        vector<int> result;
        for (int i = 0; i < (int)words.size(); ++i)
        {
            if (words[i].find(ch) != string::npos)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
//Leetcode 3541. Maximum Frequency Sum of a String
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxFreqSum(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }
        int vFreq = 0;
        int cFreq = 0;

        for (char c : s)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                vFreq = max(vFreq, freq[c]);
            }
            else
            {
                cFreq = max(cFreq, freq[c]);
            }   
        }
        return vFreq + cFreq;
    }
};
//Q30
//Problem: Substring with Concatenation of All Words
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> result;
        if (words.empty() || s.empty())
            return result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int windowLen = wordLen * wordCount;

        if (s.length() < windowLen)
            return result;

        unordered_map<string, int> wordFreq;
        for (const string &word : words)
            wordFreq[word]++;

        for (int i = 0; i < wordLen; i++)
        {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int j = i; j <= s.length() - wordLen; j += wordLen)
            {
                string word = s.substr(j, wordLen);
                if (wordFreq.find(word) != wordFreq.end())
                {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordFreq[word])
                    {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount)
                        result.push_back(left);
                }
                else
                {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};

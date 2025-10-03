//leetcode 3. Longest Substring Without Repeating Characters
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int start = 0, maxLen = 0;

        for (int end = 0; end < s.length(); ++end) {
            if (lastSeen.find(s[end]) != lastSeen.end() &&
                lastSeen[s[end]] >= start) {
                start = lastSeen[s[end]] + 1;
            }
            lastSeen[s[end]] = end;
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};

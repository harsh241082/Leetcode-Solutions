//LeetCode 168. Excel Sheet Column Title
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber){
            columnNumber--;
            char ch = (columnNumber % 26) + 'A';
            columnNumber /= 26;
            ans = ch + ans;
        }
        return ans;
    }
};
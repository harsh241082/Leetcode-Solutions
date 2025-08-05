#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int maxH=0;
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0;i<citations.size();++i)
        {
            if (citations[i] >= i+1)
                maxH = i + 1;
            else   
                break;
        }
        return maxH;
    }
};
//LeetCode 74. Search a 2D Matrix
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i =m-1;i>=0;i--){
            if(matrix[i][0]<=target){
                int low=0,high=n-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(matrix[i][mid]==target) return true;
                    else if(matrix[i][mid]<target) low=mid+1;
                    else high=mid-1;
                }
                break;
            }
        }
    }
    bool searchMatrix2(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int midValue = matrix[mid / n][mid % n];
            if (midValue == target)
                return true;
            else if (midValue < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
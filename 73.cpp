//Leetcode 73. Set Matrix Zeroes
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<bool> rows(n, false);
        vector<bool> cols(m, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //approach using inplace marking instead of sperate arrays
    void setZeroes2(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // Check if first row or column has any zero
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                firstColZero = true;
        }
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
                firstRowZero = true;
        }

        // Use first row and column as markers
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix cells to zero based on markers
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out first row and column if needed
        if (firstColZero)
        {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        if (firstRowZero)
        {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
    }
};

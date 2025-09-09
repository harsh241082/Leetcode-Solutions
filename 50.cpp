class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
            return 0.0;
        if (n == 0)
            return 1.0;
        if (x == 1)
            return 1.0;
        if (x == -1 && n % 2 == 0)
            return 1.0;
        if (x == -1 && n % 2 != 0)
            return -1.0;

        long bin = n;
        double ans = 1;
        if (bin < 0)
        {
            x = 1 / x;
            bin = -bin;
        }
        while (bin > 0)
        {
            if (bin % 2 == 1)
            {
                ans *= x;
            }
            x *= x;
            bin /= 2;
        }
        return ans;
    }
};
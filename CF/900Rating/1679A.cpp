#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n;
    cin >> n;
    // odd number of tires
    if (n % 2 == 1  || n < 4 )
    {
        cout << -1 << endl;
        return;
    }

    // for minimum buses that is we have mostly of 3 axles
    long long min_buses = (n+5) / 6;

    // maximum buses that is we have mostly of 2 axles
    long long max_buses = n / 4;
    cout << min_buses << " " << max_buses << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
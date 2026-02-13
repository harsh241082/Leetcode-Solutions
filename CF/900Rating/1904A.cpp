#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int xk, yk;
    cin >> xk >> yk;
    int xq, yq;
    cin >> xq >> yq;
    set<pair<int, int>> king_pos, queen_pos;
    int dx[] = {a, a, -a, -a, b, b, -b, -b};
    int dy[] = {b, -b, b, -b, a, -a, a, -a};

    for (int i = 0; i < 8; i++)
    {
        king_pos.insert({xk + dx[i], yk + dy[i]});
        queen_pos.insert({xq + dx[i], yq + dy[i]});
    }

    int count = 0;
    for (auto pos : king_pos)
    {
        if (queen_pos.count(pos))
            count++;
    }
    cout << count << endl;
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
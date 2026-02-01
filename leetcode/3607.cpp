// Leetcode 3607 - Power Grid Maintenance
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> processQueries(int c, vector<vector<int>> &connections,
                               vector<vector<int>> &queries)
    {
        vector<int> result;
        vector<bool> active(c + 1, true);
        vector<set<int>> graph(c + 1);
        for (const auto &conn : connections)
        {
            int u = conn[0], v = conn[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }

        for (const auto &query : queries)
        {
            int type = query[0];
            if (type == 2)
            {
                int node = query[1];
                active[node] = false;
            }
            else
            {
                int node = query[1];
                if (active[node])
                {
                    result.push_back(node);
                    continue;
                }
                else
                {   
                    result.push_back(-1);
                    for (int neighbor : graph[node])
                    {
                        if (active[neighbor])
                        {
                            result.back() = neighbor;
                            break;
                        }

                    }
                }
            }
        }
        return result;
    }
};

class Solution2
{
private:
    vector<int> parent;

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
        {
            parent[root_j] = root_i;
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>> &connections,
                               vector<vector<int>> &queries)
    {

        parent.resize(c + 1);
        iota(parent.begin(), parent.end(), 0);

        map<int, set<int>> active_stations_in_grid;

        for (int i = 1; i <= c; ++i)
        {
            active_stations_in_grid[i].insert(i);
        }

        for (const auto &conn : connections)
        {
            int u = conn[0];
            int v = conn[1];

            int root_u = find(u);
            int root_v = find(v);

            if (root_u != root_v)
            {
                unite(root_u, root_v);
                int new_root = find(root_u);
                int old_root = (new_root == root_u) ? root_v : root_u;

                if (active_stations_in_grid.count(old_root))
                {
                    active_stations_in_grid[new_root].insert(
                        active_stations_in_grid[old_root].begin(),
                        active_stations_in_grid[old_root].end());
                    active_stations_in_grid.erase(old_root);
                }
            }
        }

        vector<bool> is_online(c + 1, true);

        vector<int> result;
        for (const auto &query : queries)
        {
            int type = query[0];
            int node = query[1];

            if (type == 1)
            {
                if (is_online[node])
                {
                    result.push_back(node);
                }
                else
                {
                    int root = find(node);

                    if (active_stations_in_grid.count(root) &&
                        !active_stations_in_grid[root].empty())
                    {
                        result.push_back(
                            *active_stations_in_grid[root].begin());
                    }
                    else
                    {
                        result.push_back(-1);
                    }
                }
            }
            else if (type == 2)
            {
                if (is_online[node])
                {
                    is_online[node] = false;

                    int root = find(node);

                    if (active_stations_in_grid.count(root))
                    {
                        active_stations_in_grid[root].erase(node);
                    }
                }
            }
        }

        return result;
    }
};
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1004
#define INF 1e9

int n;
int c[MAX_N][MAX_N];
vector<int> x;
int f, f_opt = INF;
set<int> C;

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        C.insert(i);
    }
}

int select(int cur, set<int> C)
{
    int sel = -1;
    int _min = INF;
    for (set<int>::iterator it = C.begin(); it != C.end(); it++)
    {
        if (_min > c[cur][*it])
        {
            sel = *it;
            _min = c[cur][*it];
        }
    }

    // C.erase(sel);
    return sel;
}

void greedy(int start, set<int> C)
{
    int cur = start;
    vector<int> route;
    f = 0;
    route.clear();
    route.push_back(cur);
    C.erase(cur);
    while (C.size() != 0)
    {
        int sel = select(cur, C);
        f += c[cur][sel];
        route.push_back(sel);
        cur = sel;
        C.erase(sel);
    }
    f += c[cur][0];
    if (f < f_opt)
    {
        f_opt = f;
        x.clear();
        for (auto i : route)
        {
            x.push_back(i);
        }
    }
}

void solution()
{
    cout << n << '\n';
    // cout << f_opt << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << x[i] + 1 << ' ';
    }
}

int main()
{
    input();
    for (int i = 0; i < n; ++i)
    {
        greedy(i, C);
    }

    solution();
    return 0;
}
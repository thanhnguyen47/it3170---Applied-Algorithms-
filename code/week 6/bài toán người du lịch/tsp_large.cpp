#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000

int n;
int c[MAX_N][MAX_N];
int f, f_opt = INT_MAX;
vector<int> x, x_opt;
set<int> C;

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
        }
    }
}

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        C.insert(i);
    }
}
int select(set<int> C)
{
    int minC = INT_MAX;
    int last = x[x.size() - 1];
    int sel = -1;
    for (set<int>::iterator it = C.begin(); it != C.end(); it++)
    {
        if (minC > c[last][*it])
        {
            minC = c[last][*it];
            sel = *it;
        }
    }

    return sel;
}

void greedy(int start, set<int> C)
{
    C.erase(start);
    f = 0;
    x.clear();
    x.push_back(start);

    while (C.size())
    {
        int sel = select(C);

        int last = x[x.size() - 1];
        x.push_back(sel);
        f += c[last][sel];
        C.erase(sel);
    }
    if (f_opt > f + c[x[n - 1]][x[0]])
    {
        f_opt = f + c[x[n - 1]][x[0]];
        x_opt.clear();
        for (int i = 0; i < n; i++)
        {
            x_opt.push_back(x[i]);
        }
    }
}

int main()
{
    input();
    init();
    for (int i = 1; i <= n; ++i)
    {
        greedy(i, C);
    }

    cout << n << '\n';
    for (int a : x_opt)
    {
        cout << a << ' ';
    }
    return 0;
}
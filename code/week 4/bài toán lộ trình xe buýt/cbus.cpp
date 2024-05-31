

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 11

int n, k;
int c[2 * MAX_N + 1][2 * MAX_N + 1];
int c_min = INT_MAX;
bool visited[2 * MAX_N + 1];
int load; // the current number of passengers
int x[2 * MAX_N + 1];
int f, f_opt = INT_MAX;

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; ++i)
    {
        for (int j = 0; j <= 2 * n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j])
                c_min = min(c_min, c[i][j]);
        }
    }
    visited[0] = true;
    x[0] = 0;
}

bool check(int v)
{
    if (visited[v])
        return false;
    if (v <= n && load == k)
        return false;
    if (v > n && !visited[v - n])
        return false;

    return true;
}

void solution()
{
    f_opt = min(f_opt, f + c[x[2 * n]][0]);
    // for (int i = 0; i <= 2 * n; ++i)
    // {
    //     cout << x[i] << ' ';
    // }
    // cout << '\n';
}
void Try(int t)
{
    for (int v = 1; v <= 2 * n; ++v)
    {
        if (check(v))
        {
            x[t] = v;
            visited[v] = true;
            if (v > n)
                --load;
            else
                ++load;
            f += c[x[t - 1]][v];

            if (t == 2 * n)
            {
                solution();
            }
            else if (f + (2 * n - t + 1) * c_min < f_opt) // +1 là để quay về 0
            {
                Try(t + 1);
            }

            visited[v] = false;
            if (v > n)
                ++load;
            else
                --load;
            f -= c[x[t - 1]][v];
        }
    }
}

int main()
{
    input();
    Try(1);
    cout << f_opt << endl;
}
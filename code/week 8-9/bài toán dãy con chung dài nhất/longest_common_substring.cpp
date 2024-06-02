#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000
string X, Y;
int mem[MAX_N][MAX_N];

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> X >> Y;

    memset(mem, -1, sizeof(mem));
}

int LCS(int i, int j)
{
    if (i == 0 || j == 0)
        return 0;
    if (mem[i][j] != -1)
        return mem[i][j];

    int res = 0;
    res = max(LCS(i - 1, j), LCS(i, j - 1));
    if (X[i - 1] == Y[j - 1])
    {
        res = max(res, LCS(i - 1, j - 1) + 1);
    }

    mem[i][j] = res;
    return res;
}

void Trace(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (X[i - 1] == Y[j - 1] && LCS(i, j) == LCS(i - 1, j - 1) + 1)
    {
        Trace(i - 1, j - 1);
        cout << X[i - 1] << ' ';
        return;
    }

    if (LCS(i, j) == LCS(i - 1, j))
    {
        Trace(i - 1, j);
        return;
    }
    if (LCS(i, j) == LCS(i, j - 1))
    {
        Trace(i, j - 1);
        return;
    }
}

int main()
{
    input();
    cout << LCS(X.length(), Y.length()) << '\n';
    Trace(X.length(), Y.length());
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAX_N 20

const int XMAX = 1e5 + 5;

int n, x;
int D[MAX_N];
int mem[MAX_N][XMAX];

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> D[i];
    }

    sort(D, D + n);
    memset(mem, -1, sizeof(mem));
}

int minCoin(int i, int x)
{
    if (x < 0 || i == 0)
        return INF;
    if (x == 0)
    {
        mem[i][x] = 0;
        return 0;
    }
    if (mem[i][x] != -1)
        return mem[i][x];

    int res = min(1 + minCoin(i, x - D[i]), minCoin(i - 1, x));
    mem[i][x] = res;

    return res;
}
void Trace(int i, int x)
{
    if (x <= 0 || i == 0)
        return;

    if (mem[i][x] == 1 + mem[i][x - D[i]])
    {
        cout << D[i] << ' ';
        Trace(i, x - D[i]);
    }
    else
        Trace(i - 1, x);
}
int main()
{
    input();
    cout << minCoin(n, x) << '\n';
    Trace(n, x);
}
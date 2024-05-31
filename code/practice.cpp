#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20

int n;
int H, W;
int h[MAX_N], w[MAX_N];
int x[MAX_N], y[MAX_N], o[MAX_N];
int mark[MAX_N][MAX_N];

bool flag = false;

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> W;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i] >> w[i];
    }
}

bool check(int vh, int vw, int hk, int wk)
{
    for (int i = vh; i < vh + hk; ++i)
    {
        for (int j = vw; j < vw + wk; ++j)
        {
            if (mark[i][j])
                return false;
        }
    }
    return true;
}

void doMark(int vh, int vw, int hk, int wk, bool markVal)
{
    for (int i = vh; i < vh + hk; ++i)
    {
        for (int j = vw; j < vw + wk; ++j)
        {
            mark[i][j] = markVal;
        }
    }
}
void Try(int k)
{
    for (int vo = 0; vo <= 1; ++vo)
    {
        int hk = h[k], wk = w[k];
        if (vo)
        {
            hk = w[k];
            wk = h[k];
        }

        for (int vh = 0; vh <= H - hk; ++vh)
        {
            for (int vw = 0; vw <= W - wk; ++vw)
            {
                if (check(vh, vw, hk, wk))
                {
                    x[k] = vh;
                    y[k] = vw;
                    o[k] = vo;
                    doMark(vh, vw, hk, wk, true);

                    if (k == n)
                    {
                        flag = true;
                        return;
                    }
                    else
                        Try(k + 1);

                    doMark(vh, vw, hk, wk, false);
                }
            }
        }
    }
}

int main()
{
    input();
    Try(1);
    cout << flag ? 1 : 0;
    return 0;
}
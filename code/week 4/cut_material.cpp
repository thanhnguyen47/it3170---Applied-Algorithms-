/*
Description
Given a material having the shape rectangle with height H and width W.
We need to cut this material into n smaller rectangle submaterials of size (h1,w1), (h2, w2), ..., (hn, wn).
Write a program to check if we can perform this cut.

Input
Line 1: contains two positive integers H, W (1 <= H, W <= 10)
Line 2: contains a positive integer n (1 <= n <= 10)
Line i+2 (i= 1,...,n): contains two positive integer hi and wi (1 <= hi, wi <= 10)

Output
Write 1 if we can perform the cut and write 0, otherwise.

Example
Input
7 5
4
1 5
6 2
2 2
4 3
Output
1
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10

int H, W;
int n;
bool c[MAX_N][MAX_N]; // mark the rectangle material
int h[MAX_N + 1];
int w[MAX_N + 1];
int o[MAX_N + 1];
int hk, wk, ok;

bool flag;

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> H >> W;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i] >> w[i];
        // o[i] = 0; // no rotation by default
    }
}

bool check(int vh, int vw, int hk, int wk)
{
    // staring point and its sizes
    for (int i = vh; i < vh + hk; ++i)
    {
        for (int j = vw; j < vw + wk; ++j)
        {
            if (c[i][j])
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
            c[i][j] = markVal;
        }
    }
}
void Try(int k)
{
    for (int vo = 0; vo <= 1; ++vo)
    {
        hk = h[k];
        wk = w[k];
        o[k] = vo;
        if (vo == 1)
        {
            hk = w[k];
            wk = h[k];
        }
        // starting coordinates for the sub-material
        for (int vh = 0; vh <= H - hk; ++vh)
        {
            for (int vw = 0; vw <= W - wk; ++vw)
            {
                if (check(vh, vw, hk, wk))
                {
                    doMark(vh, vw, hk, wk, true);

                    if (k == n)
                    {
                        flag = true;
                        return;
                    }
                    else
                        Try(k + 1);

                    doMark(vh, vw, hk, wk, false); // undo mark
                }
            }
        }
    }
}

int main()
{
    input();
    Try(1);

    if (flag)
        cout << '1' << '\n';
    else
        cout << '0' << '\n';
    return 0;
}
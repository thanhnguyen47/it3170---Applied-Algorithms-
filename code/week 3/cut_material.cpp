/*
Bài toán:
Cho một miếng vật liệu có hình chữ nhật H*W.
Cần cắt thành n hình chữ nhật nhỏ kích thước (h1, w1), (h2, w2), .., (hn, wn).
*/

#include <bits/stdc++.h>
using namespace std;

int H, W;
int n;
int h[100], w[100];
bool mark[100][100];

int x[100], y[100];
int o[100]; // xac dinh trang thai xoay 90deg cua mieng con.
bool flag; // luu ket qua

bool check(int vo, int vx, int vy, int k)
{
    int wk = w[k];
    int hk = h[k];
    if (vo == 1)
    {
        wk = h[k];
        hk = w[k];
    }
    if (vx + wk > W) return false;
    if (vy + hk > H) return false;

    for (int i = vx; i <= vx + wk - 1; ++i) {
        for (int j = vy; j <= vy + hk - 1; ++j) {
            if (mark[i][j]) return false;
        }
    }
    return true;
}

void doMark(int vo, int vx, int vy, int k, bool markVal){
    int wk = w[k];
    int hk = h[k];
    if (vo == 1) {
        wk = h[k];
        hk = w[k];
    }

    for (int i = vx; i <= vx + wk - 1; ++i) {
        for (int j = vy; j <= vy + hk - 1; ++j) {
            mark[i][j] = markVal;
        }
    }
}

void Try(int k)
{
    for (int vo = 0; vo <= 1; ++vo)
    {
        int wk = w[k];
        int hk = h[k];
        if (vo == 1)
        {
            wk = h[k];
            hk = w[k];
        }

        for (int vx = 0; vx <= W - wk; ++vx)
        {
            for (int vy = 0; vy <= H - hk; ++vy)
            {
                if (check(vo, vx, vy, k))
                {
                    x[k] = vx; y[k] = vy; o[k] = vo;
                    doMark(vo, vx, vy, k, true);

                    if (k == n) {
                        flag = true;
                        return;
                    }
                    else {
                        Try(k + 1);
                    }

                    doMark(vo, vx, vy, k, false); //undo mark
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i] >> w[i];
    }

    Try(1);
    if (flag) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}
/*
test case:
7 5
4
1 5
6 2
2 2
4 3

correct output:
1
*/
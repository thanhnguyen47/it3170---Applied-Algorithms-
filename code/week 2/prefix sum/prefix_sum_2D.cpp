#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1004
#define MAX_M 1004

int n, m;
int arr[MAX_N][MAX_M]; // i = 1..n, j = 1..m
int Q;
int r1, c1, r2, c2;

int s[MAX_N][MAX_M];

void preprocess()
{
    // for (int i = 0; i <= n; ++i)
    // {
    //     s[i][0] = 0;
    // }
    // for (int j = 0; j <= m; ++j)
    // {
    //     s[0][j] = 0;
    // }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + arr[i][j];
        }
    }
}

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    cin >> Q;
}
int main()
{
    input();
    preprocess();

    while (Q--)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000004

int n;
int arr[MAX_N];
int K;
int res = 0;
// Tính M[i,j] là chỉ số của phần tử nhỏ nhất của dãy con bắt đầu từ aj và có 2^i phần tử, với i = 0, 1, 2, …, log2(N+1) và j = 0, 1, 2, …, N-1.
int M[30][MAX_N];

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> K;
}

void preprocess()
{
    for (int i = 0; i < n; ++i)
    {
        M[0][i] = i;
    }

    for (int i = 1; (1 << i) <= n; ++i)
    {
        for (int j = 0; j + (1 << i) - 1 < n; ++j)
        {
            if (arr[M[i - 1][j]] < arr[M[i - 1][j + (1 << (i - 1))]])
            {
                M[i][j] = M[i - 1][j];
            }
            else
                M[i][j] = M[i - 1][j + (1 << (i - 1))];
        }
    }
}

int getMinIndex(int i, int j)
{
    int k = int(log2(j - i + 1));
    if (arr[M[k][i]] < arr[M[k][j - (1 << k) + 1]])
        return M[k][i];
    else
        return M[k][j - (1 << k) + 1];
}

int main()
{
    input();
    preprocess();
    while (K--)
    {
        int i, j;
        cin >> i >> j;
        res += arr[getMinIndex(i, j)];
    }

    cout << res;
    return 0;
}
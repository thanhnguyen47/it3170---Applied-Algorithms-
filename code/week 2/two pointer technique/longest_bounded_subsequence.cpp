#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000004

int n;
int arr[MAX_N];
int Q;
int s;
int res = -1;
void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> Q;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
}
int main()
{
    input();

    int i = 0; // con trỏ chạy bên trái
    for (int j = 0; j < n; ++j)
    {
        s += arr[j];
        // Tại mỗi vòng lặp, cố định bên phải và điều chỉnh bên trái dãy con.
        while (s > Q)
        {
            s -= arr[i];
            ++i;
            res = max(res, j - i + 1);
        }
    }

    cout << res;
}
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000004

int n;
int arr[MAX_N];
int Q;

int cnt; // the result

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
    int i = 0, j = n - 1;

    sort(arr, arr + n);
    while (i < j)
    {
        int s = arr[i] + arr[j];
        if (s == Q)
        {
            ++cnt;
            ++i;
            --j;
        }
        else if (s > Q)
            --j;

        else if (s < Q)
            ++i;
    }

    cout << cnt;

    return 0;
}
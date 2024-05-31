#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000004

int n;
int arr[MAX_N];

int maxLeft(int *arr, int l, int r)
{
    int sum = 0;
    int _max = -1e9;
    for (int i = r; i >= l; --i)
    {
        sum += arr[i];
        _max = max(_max, sum);
    }

    return _max;
}

int maxRight(int *arr, int l, int r)
{
    int sum = 0;
    int _max = -1e9;
    for (int i = l; i <= r; ++i)
    {
        sum += arr[i];
        _max = max(_max, sum);
    }

    return _max;
}

int maxSeq(int *arr, int l, int r)
{
    if (l == r)
        return arr[l];

    int mid = (l + r) / 2;
    int mL = maxSeq(arr, l, mid);
    int mR = maxSeq(arr, mid + 1, r);
    int mLR = maxLeft(arr, l, mid) + maxRight(arr, mid + 1, r);

    return max(max(mL, mR), mLR);
}

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
}
int main()
{
    input();
    int res = maxSeq(arr, 0, n - 1);
    cout << res;

    return 0;
}
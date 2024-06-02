#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000004

int n, x;
int arr[MAX_N];

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
}

int bsearch(int *arr, int l, int r, int val)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == val)
        return mid;
    else if (arr[mid] > val)
        return bsearch(arr, l, mid - 1, val);
    else
        return bsearch(arr, mid + 1, r, val);
}

int main()
{
    input();
    cout << bsearch(arr, 0, n - 1, x) + 1;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int n;
int arr[MAX_N];
vector<int> temp;
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

void merge(int *arr, int l, int r)
{
    int m = (l + r) / 2;

    int i = l, j = m + 1;
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= m)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= r)
    {
        temp.push_back(arr[j++]);
    }

    for (int i = l; i <= r; ++i)
    {
        arr[i] = temp[i - l];
    }
    temp.clear();
}

void merge_sort(int *arr, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, r);
}

int main()
{
    input();
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ' ';
    }
}
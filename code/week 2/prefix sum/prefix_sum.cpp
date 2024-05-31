#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000004
int n;
int arr[MAX_N];
int Q;
int i, j;
int s[MAX_N];

void preprocess()
{
    s[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        s[i] = s[i - 1] + arr[i];
    }
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

    cin >> Q;
}

int main()
{
    input();
    preprocess();

    while (Q--)
    {
        cin >> i >> j;
        cout << s[j - 1] - s[i - 1 - 1] << '\n';
    }

    return 0;
}
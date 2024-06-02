#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 4;

int n;
int arr[MAX_N], mem[MAX_N];

int ans, pos;

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    memset(mem, -1, sizeof(mem));
}

int LIS(int i)
{
    if (mem[i] != -1)
        return mem[i];

    int res = 1;
    for (int j = 1; j < i; ++j)
    {
        if (arr[j] < arr[i])
        {
            res = max(res, 1 + LIS(j));
        }
    }
    mem[i] = res;
    return res;
}

void solve()
{
    for (int i = 1; i <= n; ++i)
    {
        if (ans < LIS(i))
        {
            ans = LIS(i);
            pos = i;
        }
    }
    cout << ans << '\n';
}

void Trace(int i) {
    for (int j = i - 1; j >= 1; --j) {
        if (arr[j] < arr[i] && LIS(i) == 1 + LIS(j)) {
            Trace(j);
            break;
        }
    }
    cout << arr[i] << ' ';
}

int main() {
    input();
    solve();
    Trace(pos);

    return 0;
}
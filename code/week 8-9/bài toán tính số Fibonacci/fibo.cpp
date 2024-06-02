#include <bits/stdc++.h>
using namespace std;

#define MAX_N 93
#define ull unsigned long long

int n;
ull f[MAX_N];
// map<int, int> mem; // đánh dấu kết quả đã được ghi nhận hay chưa.

// int Fibo(int k)
// {
//     if (k <= 2)
//         return 1;
//     if (mem.find(k) != mem.end())
//         return mem[k];

//     int res = Fibo(k - 1) + Fibo(k - 2);
//     mem[k] = res;
//     return res;
// }

void init()
{
    memset(f, -1, sizeof(f));
}

ull Fibo(int k)
{
    if (k <= 2)
        return 1;
    if (f[k] != -1)
        return f[k];
    ull res = Fibo(k - 1) + Fibo(k - 2);
    f[k] = res;
    return res;
}

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
}

int main()
{
    // cout << ULLONG_MAX << endl;
    input();
    init();
    cout << Fibo(n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int Q = 1e9 + 7;
int x, n; // x^n

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> n;
    x = x % Q;
}

int pow_mod(int x, int n)
{
    if (n == 1)
        return x % Q;
    int t = pow_mod(x, n / 2) % Q;
    if (n % 2 == 0)
        return t * t % Q;
    else
        return t * t % Q * x % Q;
}

int main()
{
    input();
    cout << pow_mod(x, n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 93
#define ll long long
int n, i;
ll fibo[MAX_N];

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> i;
}

void preprocess()
{
    fibo[1] = fibo[2] = 1;
    for (int i = 3; i < MAX_N; ++i)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

char findFiboChar(int i, int n)
{
    // cout << n << ' ' << fibo[n] << endl;
    if (i > fibo[n])
        return '-';
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';

    if (i <= fibo[n - 2])
    {
        return findFiboChar(i, n - 2);
    }
    else
        return findFiboChar(i - fibo[n - 2], n - 1);
}

int main()
{
    input();
    preprocess();
    cout << findFiboChar(i, n);
}
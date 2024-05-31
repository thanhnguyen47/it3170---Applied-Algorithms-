#include <bits/stdc++.h>
using namespace std;

const int Q = INT_MAX; // lấy Q lớn nhất có thể để tránh collision (xung đột)
const int d = 256;

string P, T;

int hashCode(string p)
{
    int c = 0;
    for (int i = 0; i < p.length(); ++i)
    {
        c = c * d + p[i];
        c %= Q;
    }
    return c;
}

int hashCode(string s, int start, int end)
{
    int c = 0;
    for (int i = start; i <= end; ++i)
    {
        c = c * d + s[i];
        c %= Q;
    }
    return c;
}

int get_e(int n)
{
    if (n == 1)
        return d;
    int t = get_e(n / 2) % Q;
    t = t * t % Q;
    if (n % 2 == 0)
        return t;
    else
        return (t * d) % Q;
}

int rabinKarp(string P, string T)
{
    int cnt = 0;
    int n = T.length();
    int m = P.length();
    int e = get_e(m - 1);

    int codeP = hashCode(P);
    int codeT = hashCode(T, 0, m - 1);

    for (int s = 0; s <= n - m; ++s)
    {
        if (codeP == codeT)
        {
            bool flag = true;
            for (int j = 0; j < m; ++j)
            {
                if (P[j] != T[s + j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ++cnt;
        }
        if (s < n - m)
        {
            codeT = (d * (codeT - T[s] * e) + T[s + m]) % Q;
            if (codeT < 0)
                codeT += Q; // cần xử lý trường hợp tràn số.
        }
    }

    return cnt;
}

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, P);
    getline(cin, T);
}

int main()
{
    input();

    cout << rabinKarp(P, T);

    return 0;
}
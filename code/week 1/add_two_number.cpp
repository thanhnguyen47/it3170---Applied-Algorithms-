#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull a, b;

int main()
{
    cin >> a >> b;
    // cout << ULLONG_MAX;

    ull a1 = a / 10, a2 = a % 10;
    ull b1 = b / 10, b2 = b % 10;

    ull c2 = (a2 + b2) % 10;
    ull r = (a2 + b2) / 10;
    ull c1 = a1 + b1 + r;
    if (c1)
        cout << c1;
    cout << c2;
}
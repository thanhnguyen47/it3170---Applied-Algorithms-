// Description
// There are n passengers 1, 2, …, n.
// The passenger i want to travel from point i to point i + n (i = 1,2,…,n).
// There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus).
// You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n).
// Compute the shortest route for the bus, serving n passengers and coming back to point 0.
//
// Input
// Line 1 contains n and k (1≤n≤11,1≤k≤10)
// Line i+1 (i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
//
// Output
// Unique line contains the length of the shortest route.
//

// Example
//  Input
//  3  2
//  0  8  5  1  10  5  9
//  9  0  5  6  6  2  8
//  2  2  0  3  8  7  2
//  5  3  4  0  3  2  7
//  9  6  8  7  0  9  10
//  3  8  10  6  5  0  2
//  3  4  4  5  2  2  0
//  Output
//  25

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 11

int n, k;
int c[2 * MAX_N + 1][2 * MAX_N + 1];
int c_min = INT_MAX;
bool visited[2 * MAX_N + 1];
int load; // the current number of passengers
int x[2 * MAX_N + 1];
int f, f_opt = INT_MAX;

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; ++i)
    {
        for (int j = 0; j <= 2 * n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j])
                c_min = min(c_min, c[i][j]);
        }
    }
    visited[0] = true;
    x[0] = 0;
}

bool check(int v)
{
    if (visited[v])
        return false;
    if (v <= n && load == k)
        return false;
    if (v > n && !visited[v - n])
        return false;

    return true;
}

void solution()
{
    f_opt = min(f_opt, f + c[x[2 * n]][0]);
    // for (int i = 0; i <= 2 * n; ++i)
    // {
    //     cout << x[i] << ' ';
    // }
    // cout << '\n';
}
void Try(int t)
{
    for (int v = 1; v <= 2 * n; ++v)
    {
        if (check(v))
        {
            x[t] = v;
            visited[v] = true;
            if (v > n)
                --load;
            else
                ++load;
            f += c[x[t - 1]][v];

            if (t == 2 * n)
            {
                solution();
            }
            else if (f + (2 * n - t + 1) * c_min < f_opt) // +1 là để quay về 0
            {
                Try(t + 1);
            }

            visited[v] = false;
            if (v > n)
                ++load;
            else
                --load;
            f -= c[x[t - 1]][v];
        }
    }
}

int main()
{
    input();
    Try(1);
    cout << f_opt << endl;
}
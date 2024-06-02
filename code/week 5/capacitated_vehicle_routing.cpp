/*
Description
A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n.
Each client i requests d[i] packages. The distance from location i to location j is c[i,j], 0≤i,j≤n.
A delivery solution is a set of routes: each truck is associated with a route, starting from depot, visiting some clients and returning to the depot for delivering requested pepsi packages such that:
 + Each client is visited exactly by one route
 + Total number of packages requested by clients of each truck cannot exceed its capacity
Goal
 + Find a solution having minimal total travel distance
Note that:
 + There might be the case that a truck does not visit any client (empty route)
 + The orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.

Input
 + Line 1: n,K,Q (2≤n≤12,1≤K≤5,1≤Q≤50)
 + Line 2: d[1],...,d[n](1≤d[i]≤10)
 + Line i+3 (i=0,…,n): the ith row of the distance matrix c (1≤c[i,j]≤30)
Output
Minimal total travel distance

Example
Input
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0

Output
70
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 15
#define MAX_K 10

int n, K, Q;
int d[MAX_N + 1]; // each client i requests d[i] packages
int c[MAX_N + 1][MAX_N + 1];
int c_min = INT_MAX;

int load[MAX_K + 1]; // current load of truck i
bool visited[MAX_N + 1];
int x[MAX_N + 1]; // x[i] is the next shipping point of point i in the route
int y[MAX_K + 1]; // y[k] is the first shipping point of the truck k
int nbR;          // the number of trucks that actually works
int segments;
int f, f_opt = INT_MAX;

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j])
                c_min = min(c_min, c[i][j]);
        }
    }
    y[0] = 0;
}

void updateSolution()
{
    f_opt = min(f_opt, f);
}

bool checkX(int v, int k)
{
    if (v > 0 && visited[v])
        return false;
    if (load[k] + d[v] > Q)
        return false;

    return true;
}

bool checkY(int v, int k)
{
    if (v == 0)
        return true;
    if (load[k] + d[v] > Q)
        return false;
    if (visited[v])
        return false;

    return true;
}

void Try_X(int s, int k) // try for x[s]
{
    if (s == 0)
    {
        if (k < K)
            Try_X(y[k + 1], k + 1);
        return;
    }

    for (int v = 0; v <= n; ++v)
    {
        if (checkX(v, k))
        {
            x[s] = v;
            visited[v] = true;
            ++segments;
            f += c[s][v];
            load[k] += d[v];

            if (v == 0) // return to starting deport.
            {
                if (k == K)
                {
                    if (segments == n + nbR)
                        updateSolution();
                }
                else if (f + (n + nbR - segments) * c_min < f_opt)
                    Try_X(y[k + 1], k + 1);
            }
            else if (f + (n + nbR - segments) * c_min < f_opt)
                Try_X(v, k);

            visited[v] = false;
            --segments;
            f -= c[s][v];
            load[k] -= d[v];
        }
    }
}

void Try_Y(int k) // try for y[k]
{
    int s = 0;
    if (y[k - 1] > 0) // rule: if truck (k-1) is used ==> truck k has starting deport > truck (k - 1)'s one. it means: y[k] in [ y[k - 1] + 1, n ]
        s = y[k - 1] + 1;
    for (int v = s; v <= n; ++v)
    {
        if (checkY(v, k))
        {
            y[k] = v;
            if (v > 0)
                ++segments; // rule : starting point = 0 means the truck is not used.
            visited[v] = true;
            f += c[0][v];
            load[k] += d[v];

            if (k < K)
                Try_Y(k + 1); // finish y[K] firstly
            else
            {
                nbR = segments; // number of segments from 0 to each starting deport = number of trucks that are used.
                Try_X(y[1], 1); // always begin with y[1]
            }

            if (v > 0) // !!
                --segments;
            visited[v] = false;
            f -= c[0][v];
            load[k] -= d[v];
        }
    }
}

int main()
{
    input();
    Try_Y(1);

    cout << f_opt << '\n';
    return 0;
}


// Another way : Greedy - week 6
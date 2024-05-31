#include <bits/stdc++.h>
using namespace std;

#define INF -1e9
vector<int> arr, st; // st store maxVal of each node
int n;
int Q;
string query;
int l, r;

void build(int node, int L, int R)
{
    if (L == R)
    {
        st[node] = arr[L];
        return;
    }

    int mid = (L + R) / 2;
    build(2 * node, L, mid);
    build(2 * node + 1, mid + 1, R);

    st[node] = max(st[2 * node], st[2 * node + 1]);
}

int getMax(int node, int L, int R, int l, int r)
{
    if (l > R || L > r)
        return INF;
    if (l <= L && R <= r)
        return st[node];

    int mid = (L + R) / 2;
    int ml = getMax(2 * node, L, mid, l, r);
    int mr = getMax(2 * node + 1, mid + 1, R, l, r);

    return max(ml, mr);
}

void update(int node, int L, int R, int id, int value)
{
    if (id < L || id > R)
        return;
    if (L == R)
    {
        st[node] = value;
        arr[id] = value;
        return;
    }
    int mid = (L + R) / 2;
    if (id <= mid)
        update(2 * node, L, mid, id, value);
    else
        update(2 * node + 1, mid + 1, R, id, value);
    st[node] = max(st[2 * node], st[2 * node + 1]);
}

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        // int t;
        // cin >> t;
        // arr.push_back(t);
        cin >> arr[i];
    }
    st.resize(4 * n); // start by 1
    cin >> Q;
}

int main()
{
    input();
    build(1, 1, n);

    while (Q--)
    {
        cin >> query;
        if (query == "get-max")
        {
            cin >> l >> r;
            cout << getMax(1, 1, n, l, r) << '\n';
        }
        else if (query == "update")
        {
            cin >> l >> r; // say l is index and r is value
            update(1, 1, n, l, r);
        }
        else
        {
            cout << "invalid command. Try again\n";
            Q++;
        }
    }
    return 0;
}
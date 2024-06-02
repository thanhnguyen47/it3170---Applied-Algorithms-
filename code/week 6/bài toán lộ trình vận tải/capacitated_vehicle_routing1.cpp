#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000
#define MAX_K 10000

int n, K, Q;
int d[MAX_N];         // client requests
int c[MAX_N][MAX_N];  // distance
vector<int> p[MAX_K]; // track routes of trucks
int f[MAX_K];         // length of routes
int load[MAX_K];      // load of trucks
set<int> C;           // tập các ứng cử viên

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> K >> Q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
    }
    d[0] = 0;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cin >> c[i][j];
        }
    }
}

void init()
{
    for (int k = 1; k <= K; ++k)
    {
        f[k] = 0;
        load[k] = 0;
        p[k].push_back(0);
    }

    for (int i = 1; i <= n; ++i)
    {
        C.insert(i);
    }
}

/*
Chiến lược 1:
+ Mỗi bước chọn xe k là xe đang có độ dài hành trình nhỏ nhất
+ Chọn khách hàng i gần với điểm cuối cùng của hành trình xe k nhất để phục vụ mà không vi phạm tải trọng
*/
int selectTruck()
{
    int minF = INT_MAX;
    int sel = -1;
    for (int k = 1; k <= K; ++k)
    {
        if (minF > f[k])
        {
            minF = f[k];
            sel = k;
        }
    }

    return sel;
}

int selectClient(int k)
{
    int minD = INT_MAX;
    int last = p[k][p[k].size() - 1];
    int sel = -1;

    for (set<int>::iterator it = C.begin(); it != C.end(); ++it)
    {
        if (load[k] + d[*it] <= Q)
        {
            if (minD > c[last][*it])
            {
                minD = c[last][*it];
                sel = *it;
            }
        }
    }
    return sel;
}

void greedy1()
{
    while (C.size())
    {
        int k = selectTruck();
        int x = selectClient(k);

        if (x == -1)
        {
            cout << "cannot serve more clients" << '\n';
            break;
        }

        int last = p[k][p[k].size() - 1];
        load[k] += d[x];
        f[k] += c[last][x];
        p[k].push_back(x);
        C.erase(x);
    }
}
void printSolution()
{
    // thêm đoạn đường quay về vị trí 0 của mỗi xe.
    for (int k = 1; k <= K; ++k)
    {
        f[k] += c[p[k].size() - 1][0];
        p[k].push_back(0);
    }

    for (int k = 1; k <= K; ++k)
    {
        cout << "p[" << k << "]: ";
        for (int i = 0; i < p[k].size(); ++i)
        {
            cout << p[k][i] << ", ";
        }
        cout << " length = " << f[k] << endl;
    }
}
int main()
{
    input();
    init();
    greedy1();
    printSolution();
    return 0;
}
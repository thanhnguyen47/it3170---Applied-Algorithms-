/*
Thuật toán tham lam 1:
 - Mỗi bước, chọn xe k là xe đang có độ dài hành trình nhỏ nhất
 - Chọn khách hàng i gần với điểm cuối cùng của hành trình xe k nhất để phục vụ mà không vi phạm tải trọng
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int INF = 1e9;

int n, K, Q;
int d[N];
int c[N][N];
vector<int> P[100]; // itineraries/routes of trucks
int F[100];         // length of itineraries
int load[100];      // load of trucks

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
        F[k] = 0;
        load[k] = 0;
        P[k].clear();
        P[k].push_back(0);
    }
}

void printSolution()
{
    // thêm đoạn đường quay về vị trí 0 của mỗi xe.
    for (int k = 1; k <= K; ++k)
    {
        F[k] += c[P[k].size() - 1][0];
        P[k].push_back(0);
    }

    for (int k = 1; k <= K; ++k)
    {
        cout << "P[" << k << "]: ";
        for (int i = 0; i < P[k].size(); ++i)
        {
            cout << P[k][i] << ", ";
        }
        cout << " length = " << F[k] << endl;
    }
}

// Mỗi bước, chọn xe k là xe đang có độ dài hành trình nhỏ nhất
int selectTruck()
{
    int minF = INF;
    int select = -1;

    for (int k = 1; k <= K; ++k)
    {
        if (minF > F[k])
        {
            minF = F[k];
            select = k;
        }
    }

    return select;
}

// Chọn khách hàng i gần với điểm cuối cùng của hành trình xe k nhất để phục vụ mà không vi phạm tải trọng
int selectClient(set<int> &C, int k)
{
    int select = -1;
    int minF = INF;
    int last = P[k][P[k].size() - 1]; // last point of itinerary k

    for (set<int>::iterator it = C.begin(); it != C.end(); it++)
    {
        int i = *it;
        if (load[k] + d[i] <= Q)
        {
            if (minF > c[last][i])
            {
                minF = c[last][i];
                select = i;
            }
        }
    }

    return select;
}

void greedy1()
{
    init();
    cout << "greedy 1 ..." << endl;
    set<int> C;
    for (int i = 1; i <= n; ++i)
        C.insert(i);

    while (C.size() > 0)
    {
        int k = selectTruck();
        int x = selectClient(C, k);

        if (x == -1)
        {
            cout << "cannot serve more clients" << endl;
            break;
        }

        int last = P[k][P[k].size() - 1];
        load[k] += d[x];
        F[k] += c[last][x];
        P[k].push_back(x);
        C.erase(x);
    }

    printSolution();
}

int main()
{
    input();
    greedy1();
    return 0;
}
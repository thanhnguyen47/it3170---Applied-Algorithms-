/*
Thuật toán tham lam 2:
 - Tại mỗi bước, chọn cặp xe k  và khách hàng i sao cho khi thêm điểm khách hàng i vào buối hành trình của xe k
 thì độ dài của hành trình xe dài nhất là ít nhất và không vi phạm ràng buộc về tải trọng
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int INF = 1e9;

int n, K, Q;
int d[N];
int c[N][N];
vector<int> P[100]; // itineraries of trucks
int F[100];         // length of itineraries
int load[100];

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
// Tại mỗi bước, chọn cặp xe k  và khách hàng i sao cho khi thêm điểm khách hàng i vào buối hành trình của xe k
// thì độ dài của hành trình xe dài nhất là ít nhất và không vi phạm ràng buộc về tải trọng
pair<int, int> selectTruckClient(set<int> &C)
{
    int sel_k = -1;
    int sel_i = -1;
    int minF = INF;

    for (int k = 1; k <= K; ++k)
    {
        for (set<int>::iterator it = C.begin(); it != C.end(); it++)
        {
            int i = *it;
            int last = P[k][P[k].size() - 1];
            if (load[k] + d[i] > Q)
                continue;

            // tìm độ dài hành trình xe dài nhất.
            int maxL = F[k] + c[last][i];
            for (int j = 1; j <= K; ++j)
            {
                if (j != k)
                {
                    maxL = max(maxL, F[j]);
                }
            }

            if (minF > maxL)
            {
                minF = maxL;
                sel_k = k;
                sel_i = i;
            }
        }
    }

    return make_pair(sel_k, sel_i);
}

void greedy2()
{
    init();
    cout << "greedy 2..." << endl;
    set<int> C;
    for (int i = 1; i <= n; ++i)
        C.insert(i);

    while (!C.empty())
    {
        pair<int, int> s = selectTruckClient(C);
        if (s.first == -1)
        {
            cout << "cannot serve more clients" << endl;
            break;
        }

        int k = s.first, x = s.second;
        int last = P[k][P[k].size() - 1];
        F[k] += c[last][x];
        load[k] += d[x];
        P[k].push_back(x);
        C.erase(x);
    }

    printSolution();
}

int main()
{
    input();
    greedy2();
    return 0;
}
/*
Cho N điểm 1..N. Khoảng cách từ điểm i đến j là d(i, j).
Hãy tìm hành trình xuất phát từ điểm 1, đi qua các điểm còn lại, mỗi
điểm đúng 1 lần và quay về điểm 1 với tổng khoảng cách (độ dài của hành trình) là ngắn nhất.


Ý tưởng tham lam: chọn điểm gần nhất để đi đến tiếp theo.

--> Không đảm bảo đưa ra lời giải tối ưu

Example:
4
0 3 4 2
1 0 5 6
3 1 0 4
3 2 7 0

--> Lời giải tham lam: 1 4 2 3 1 với độ dài = 12
--> Lời giải tối ưu: 1 3 4 2 1 với độ dài = 11
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int d[N][N];
int n;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> d[i][j];
        }
    }
}

int selectMin(set<int> &C, int cur)
{
    int minD = INT_MAX;
    int select = -1;

    for (set<int>::iterator it = C.begin(); it != C.end(); ++it)
    {
        int i = *it;
        if (minD > d[cur][i])
        {
            minD = d[cur][i];
            select = i;
        }
    }

    return select;
}

void greedy()
{
    set<int> C; // lưu lại các điểm chưa thăm, tập các ứng cử viên
    for (int i = 2; i <= n; ++i)
        C.insert(i);
    int cur = 1;
    vector<int> S; // lưu lại route
    S.push_back(cur);
    int F = 0; // độ dài hành trình hiện tại
    while (!C.empty())
    {
        int x = selectMin(C, cur);
        C.erase(x);
        F += d[cur][x];
        S.push_back(x);
        cur = x;
    }

    F += d[cur][1];
    for (auto x : S)
    {
        cout << x << ' ';
    }

    // cout << 1 << " with length = ";
    cout << '\n';
    cout << F << endl;
}

int main()
{
    input();
    greedy();
    return 0;
}
/*
Bài toán: 
Một xe buýt xuất phát từ điểm 0 cần được tính toán lộ trình đưa đón n khách và quay trở về 0
Khách i đón tại i và trả tại i + n.
Xe chỉ có K chỗ ngồi
khoảng cách từ i đến j là d[i, j]

--> Tính lộ trình nhỏ nhất, đồng thời số hành khách không vượt quá K tại mỗi thời điểm.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int K; 
int x[1000]; // luu lai lo trinh
int c[1000][1000]; // luu khoang cach giua cac diem
int cmin = INT_MAX; // khoang cach nho nhat giua hai diem
int visited[1000];
int load; // so khach hien tai tren xe
int f; // do dai lo trinh bo phan
int f_opt = INT_MAX; // lo trinh ky luc (toi uu)

bool check(int v) {
    if (visited[v]) return false;

    if (v > n) {
        if (!visited[v - n]) return false;
    }
    else if (load + 1 > K) return false;

    return true;
}

void updateBest() {
    if(f + c[x[2*n]][0] < f_opt) f_opt = f + c[x[2*n]][0];
}

void Try(int k) {
    for (int v = 1; v <= 2*n; ++v) {
        if (check(v)) {
            x[k] = v;
            f += c[x[k - 1]][x[k]];
            visited[v] = true;
            if (v <= n) ++load;
            else --load;

            if (k == 2*n) updateBest();
            else {
                if (f + cmin * (2*n - k + 1) < f_opt) {
                    Try(k + 1);
                }
            }

            f -= c[x[k - 1]][x[k]];
            visited[v] = false;
            if (v <= n) --load;
            else ++load;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> K;
    for (int i = 0; i <= 2*n; ++i) {
        for (int j = 0; j <= 2*n; ++j) {
            cin >> c[i][j];
            if (c[i][j] != 0)
                cmin = min(cmin, c[i][j]);
        }
    }

    Try(1);
    cout << f_opt << '\n';
    return 0;
}
/*
test case:
5 3
0 2 3 4 2 3 4 5 3 8 7
5 0 1 4 6 1 4 2 9 8 2
1 2 0 4 2 3 4 5 3 6 2
2 2 3 0 2 3 4 5 3 8 4
5 2 3 4 0 3 4 5 3 9 7
1 2 3 1 2 0 4 2 2 8 2
2 2 3 4 2 3 0 5 3 2 7
3 2 3 6 2 3 4 0 3 1 1
5 2 3 4 2 3 4 5 0 8 7
1 2 3 5 2 3 4 5 3 0 9
8 2 3 4 2 3 4 5 3 2 0

correct output
24
*/
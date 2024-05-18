/*
Mảng cộng dòn 2 chiều 
Cho mảng 2 chiều a[1..n, 1..m], mảng cộng dồn s[1..n, 1..m] được định nghĩa như sau:
    + s[0,j] = 0, s[i, 0] = 0, i = 0..n và j = 0..m
    + Công thức truy hồi: s[i, j] = s[i-1, j] + s[i, j-1] - s[i-1, j-1] + a[i, j]
--> độ phức tạp: O(nm)

Bài toán: Ta cần thực hiện Q truy vấn, mỗi truy vấn có dạng (a, b, c, d) được định nghĩa như sau:
    query[a, b, c, d] = ∑(k=a..c)∑(q=b..d) a[k, q]

--> Công thức truy hồi: query[a, b, c, d] = s[c, d] - s[c, b-1] - s[a-1, d] + s[a-1, b-1];
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1004][1004];
int s[10004][1004];
int Q;
int r1, c1, r2, c2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + arr[i][j];
        }
    }

    cin >> Q;
    while (Q) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1] << '\n';
        --Q;
    }

    return 0;
}
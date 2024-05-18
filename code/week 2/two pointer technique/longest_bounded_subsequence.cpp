/*
Bài toán:
Cho dãy số không âm a1, .. , an.
Cho trước giá trị Q. 
Hãy tìm dãy con (gồm 1 số phần tử liên tiếp cạnh nhau) dài nhất có tổng <= Q

==> In ra số phần tử của dãy đó.

y/c: Độ phức tạp: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000000];
int Q;
int res;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> Q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int i = 0;
    int s = 0;
    for (int j = 0; j < n; ++j) {
        // Tại mỗi vòng lặp, cố định bên phải và điều chỉnh bên trái dãy con.
        s += a[j];
        while(s > Q) {
            s -= a[i]; ++i;
        }
        res = max(res, j - i + 1);
    }

    cout << res << '\n';

    return 0;
}
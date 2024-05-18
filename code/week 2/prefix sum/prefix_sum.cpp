/*
Mảng cộng dồn:
Cho dãy a1, a2, .. an. Thực hiện Q truy vấn, mỗi truy vấn được đặc trưng bởi
cặp chỉ số (i, j) trong đó cần tính tổng ai + .. + aj 
--> Độ phức tạp: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int a[10000];
int Q;
int i, j;
int s[10000];// lưu mảng cộng dồn

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    
    cin >> Q;
    while(Q) {
        cin >> i >> j;
        cout << s[j] - s[i - 1] << '\n';
        --Q;
    }
    return 0;
}
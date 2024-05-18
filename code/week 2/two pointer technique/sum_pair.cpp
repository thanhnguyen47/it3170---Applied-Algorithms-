/*
Sum pair of sequence equal to a number

Bài toán:
Cho dãy a1, .. , an [được sắp xếp tăng dần] (các phần tử đôi một khác nhau)
Cho trước giá trị Q, hãy đếm số cặp 2 chỉ số i và j sao cho a[i] + a[j] = Q

--> Độ phức tạp: O(n)
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Nếu mảng chưa sắp xếp thì cần sắp xếp mảng
    sort(a, a+n);

    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] + a[j] == Q) {
            ++res;
            ++i;
            --j;
        }
        else if (a[i] + a[j] < Q) {
            ++i;
        }
        else {
            --j;
        }
    }

    cout << res << '\n';
    return 0;
}
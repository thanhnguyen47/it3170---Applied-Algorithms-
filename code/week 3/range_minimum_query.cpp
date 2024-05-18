/*
Bài toán:
Cho dãy a[n]. Cho số nguyên dương K là số truy vấn
mỗi truy vấn dạng (i, j) trả về chỉ số của phần tử nhỏ nhất của dãy ai .. aj

*/

#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000000];
int K;
int M[24][1000000];
int i, j;

void preprocessing() {
    for (int j = 0; j < n; ++j) {
        M[0][j] = j;
    }

    for (int i = 1; (1<<i) <= n; ++i) {
        for (int j = 0; j + (1<<i) - 1 < n; ++j) {
            if (a[M[i-1][j]] > a[M[i-1][j+(1<<(i-1))]]) {
                M[i][j] = M[i-1][j+(1<<(i-1))];
            }
            else {
                M[i][j] = M[i-1][j];
            }
            // cout << M[i][j] << ' ';
        }
        // cout << endl;
    }

}

int main() {
    cin >> n;
    for  (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    preprocessing();

    cin >> K;
    while(K--) {
        cin >> i >> j;
        int p = log2(j - i + 1);
        if (a[M[p][i]] > a[M[p][j-(1<<p)+1]]) {
            cout << M[p][j - (1<<p) + 1] << '\n';
        }
        else {
            cout << M[p][i] << '\n';
        }
    }
    return 0;
}
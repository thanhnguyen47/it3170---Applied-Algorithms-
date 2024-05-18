/*
Bài toán: Cho dãy a1..an.
Thực hiện một dãy các thao tác:
    + update i v : gán a[i] = v
    + get-max i j : trả về giá trị lớn nhất trong dãy ai .. aj

*Nếu dùng thuật toán trực tiếp:
    + update: độ phức tạp O(1)
    + get-max: độ phức tạp O(j - i)

*Nếu dùng cấu trúc segment tree:
    + update: độ phức tạp O(logN)
    + Độ cao của cây: O(logN) --> get-max có độ phức tạp 4 * O(logN)

--> Tổng quan thì segment tree có vẻ ổn định hơn.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000004];
int l, r;
int maxVal[1000004];
int m;
string query;

void buildSegmentTree(int id, int l, int r) {
    if (l == r) {
        maxVal[id] = a[l];
        return;
    }

    int mid = (l + r)/2;
    buildSegmentTree(2*id, l, mid);
    buildSegmentTree(2*id + 1, mid + 1, r);
    maxVal[id] = max(maxVal[2*id], maxVal[2*id + 1]);
}

int getMaxFromNode (int id, int l, int r, int i, int j) {
    if (i > r || j < l) // [i, j] is disjoin with [l, r]
        return INT_MIN;
    
    if (i <= l && j >= r) 
        return maxVal[id];
    
    int mid = (l + r)/2;
    int lc = 2*id;
    int rc = 2*id + 1;
    int maxLeft = getMaxFromNode(lc, l, mid, i, j);
    int maxRight = getMaxFromNode(rc, mid + 1, r, i, j);

    return max(maxLeft, maxRight);
}

int getMax(int i, int j) {
    return getMaxFromNode(1, 1, n, i, j);
}

void updateFromNode(int id, int l, int r, int i, int val) {
    if (l > r) return; // invalid
    if (i < l || i > r) return; // invalid

    if (l == r) {
        maxVal[id] = val; // update 
        return;
    }

    int mid = (l + r)/2;
    int lc = 2*id;
    int rc = 2*id + 1;
    updateFromNode(lc, l, mid, i, val);
    updateFromNode(rc, mid + 1, r, i, val);

    maxVal[id] = max(maxVal[lc], maxVal[rc]); // update
}

void updateNode (int i, int val) {
    updateFromNode(1, 1, n, i, val);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // init segment tree 
    buildSegmentTree(1, 1, n); 

    cin >> m;
    while (m--) {
        cin >> query;
        if (query == "get-max") {
            cin >> l >> r;
            cout << getMax(l, r) << '\n';
        }
        else if (query == "update") {
            cin >> l >> r; // say l is index and r is value
            updateNode(l, r);
        }
    }


    return 0;
}

/*
test case:
10
1 10 9 7 1 4 2 4 8 10 
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10

correct output: 
4
8
9
20

*/

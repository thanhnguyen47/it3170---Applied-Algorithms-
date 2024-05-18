/*
Priority Queue
    + Lưu các phần tử, truy xuát phần tử có khóa lớn nhất/nhỏ nhất một cách hiệu quả
*/  
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
    priority_queue<int> pq; // mặc định xếp số lớn hơn lên trước trong hàng đợi
    pq.push(5);     pq.push(1);     pq.push(100);   pq.push(30);
    while(!pq.empty()) {
        int e = pq.top(); // as stack =))
        pq.pop();
        cout << "pq pop " << e << endl;
    }
    cout << "------------------------------------------------" << endl;

    //----------------------------------------------------------
    priority_queue<pii> pq2; // xếp phần tử có key lớn hơn lên trước.
    pq2.push(make_pair(4, -40));
    pq2.push(make_pair(1, -10));
    pq2.push(make_pair(9, -900));

    while(!pq2.empty()){
        pii e = pq2.top(); pq2.pop();
        cout << "pq2 pop (" << e.first << ", " << e.second << ")" << endl;
    }
    cout << "------------------------------------------------" << endl;

    //----------------------------------------------------------
    priority_queue<pii, vector<pii>, greater<pii> > pq3; // xếp tăng dần.
    pq3.push(make_pair(4, -40));
    pq3.push(make_pair(1, -10));
    pq3.push(make_pair(9, -900));
    while(!pq3.empty()){
        pii e = pq3.top(); pq3.pop();
        cout << "pq3 pop (" << e.first << ", " << e.second << ")" << endl;
    }
}
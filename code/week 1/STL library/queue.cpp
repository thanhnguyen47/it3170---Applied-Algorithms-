/*
Queue
    + Cấu trúc tuyến tính
    + Thao tác: thêm và loại bỏ phần tử với nguyên tắc First In First Out - FIFO
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    for (int e = 1; e <= 5; e++) {
        q.push(e);
        cout << "Queue push " << e << endl;
    }

    while (!q.empty()) {
        int e = q.front(); // lấy giá trị phần tử ở đầu hàng đợi, phần tử đó vẫn nằm trong hàng đợi 
        q.pop(); // lấy phần tử đầu hàng đợi ra khỏi hàng đợi
        cout << "Queue POP " << e << endl;
    }
}
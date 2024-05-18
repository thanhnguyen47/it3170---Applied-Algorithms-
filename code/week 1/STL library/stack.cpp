/*
Stack
    + Cấu trúc tuyến tính
    + Thao tác: thêm và loại bỏ phần tử với nguyên tắc Last In First Out - LIFO

*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<int> s;
    for (int i = 1; i <= 5; i++) {
        s.push(i);
        cout << "PUSH " << i << endl;
    }

    while(!s.empty()) {
        int e = s.top(); // lấy giá trị phần tử trên đỉnh stack, phần tử vẫn nằm trong ngăn xếp
        s.pop(); // lấy phần tử trên đỉnh ra khỏi ngăn xếp
        cout << "POP " << e << endl;
    }
}
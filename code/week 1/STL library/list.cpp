/*
Danh sách liên kết đôi (List)
    + Lưu các phần tử tuyến tính
    + Các thao tác: thêm phần tử vào đầu, cuối, 
    vào sau 1 vị trí, loại bỏ 1 phần tử ra khỏi danh sách
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l;
    for (int v = 1; v <= 5; v++) l.push_back(v);
    list<int>::iterator p;
    p = l.begin();
    advance(p, 2); // tăng con trỏ p lên 2 vị trí
    cout << "item at position p is " << *p << endl;
    // l.insert(p, 2, 6); // chèn 2 phần tử 6 vào sau vị trí p
    // for (p = l.begin(); p != l.end(); p++) cout << *p << " ";

    l.erase(p); // xóa phần tử ở vị trí p
    for (p = l.begin(); p != l.end(); p++) cout << *p << " ";
}
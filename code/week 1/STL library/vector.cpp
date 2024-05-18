/*
Mảng động (Vector)
    + Lưu các phần tử tuyến tính
    + Các thao tác: truy cập, thêm mới, loại bỏ các phần tử
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(1); v.push_back(2);
    for (int i = 3; i <= 10; i++) v.push_back(i);
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    v.erase(v.begin(), v.begin() + 3);
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}
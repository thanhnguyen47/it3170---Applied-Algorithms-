/*
Map
    + Cấu trúc dữ liệu lưu cặp khóa, giá trị
    + Thao tác: thêm cặp khóa, giá trị; truy vấn giá trị tương ứng với một khóa
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> m;
    m["abc"] = 1; m["def"] = 2; m["xyzt"] = 10;
    string k = "abc";
    cout << "value of key " << k << " = " << m[k] << endl;

    for (map<string, int>::iterator p = m.begin(); p != m.end(); ++p) {
        cout << p->first << " is mapped to value " << p->second << endl;
    }
    string k1 = "1234";
    cout << "value of " << k1 << " = " << m[k1] << endl; // neu chua co thi se tu khoi tao (0 neu la int)
}
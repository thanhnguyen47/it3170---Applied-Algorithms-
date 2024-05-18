/*
String
    + Biểu diễn chuỗi các ký tự
    + Thao tác: gán, ghép xâu, thay thế xâu con, trích xuất xâu con, ...
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "hello";
    string s2 = s1 + " world";
    cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
    string ss = s2.substr(2, 6); // lấy xâu con từ vị trí thứ 2, dài 6 ký tự
    cout << "s2 = " << s2 << ", length = " << s2.length() << endl;
    cout << "s2.substring(2, 6) = " << ss << endl;
    s2.replace(6, 5, "abc"); // thay thế xâu con từ vị trí thứ 6, dài 5 ký tự bằng xâu con mới "abc"
    cout << "new s2 = " << s2 << endl;
}
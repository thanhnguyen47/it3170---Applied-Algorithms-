/*
Set
    + Lưu các phần tử không lặp giá trị
    + Thao tác: thêm, loại bỏ, tìm kiếm thực hiện nhanh(O(logN))
    + upper_bound(k): trả về con trỏ đến phần tử nhỏ nhất > k.
    nếu không tìm được thì trả về s.end()
    + lower_bound(k): trả về con trỏ đến phần tử nhỏ nhất >= k.
    nếu không tìm được thì trả về s.end()
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> s;
    s.insert("abc");
    s.insert("def");
    s.insert("xyz");
    s.insert("abc");

    set<string>::iterator p;
    for (p = s.begin(); p != s.end(); ++p)
        cout << *p << " ";
    cout << endl;

    // Tìm kiếm
    string s1 = "def";
    set<string>::iterator p1 = s.find(s1);
    if (p1 == s.end())
    {
        cout << "xau " << s1 << " does not exist" << endl;
    }
    else
        cout << "xau " << s1 << " exists in the set" << endl;

    // Xóa
    string s2 = "xyz";
    s.erase(s2);
    for (p = s.begin(); p != s.end(); ++p)
        cout << *p << " ";
    cout << endl;

    /*-----------------------------------------------------------*/

    set<int> S;
    for (int v = 1; v <= 5; ++v)
        S.insert(2 * v);

    // upper_bound
    set<int>::iterator P = S.upper_bound(3);
    if (P != S.end())
    {
        cout << *P << endl;
    }

    P = S.upper_bound(4);
    if (P != S.end())
    {
        cout << *P << endl;
    }

    // lower_bound
    P = S.lower_bound(4);
    if (P != S.end())
    {
        cout << *P << endl;
    }
    P = S.lower_bound(5);
    if (P != S.end())
    {
        cout << *P << endl;
    }
}
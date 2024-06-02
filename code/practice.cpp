#include <bits/stdc++.h>
using namespace std;

string cmd, k;
set<string> database;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> k) {
        if (k == "*") break;
        database.insert(k);
    }

    while (cin >> cmd) {
        if (cmd == "***") break;
        else if (cmd == "find") {
            cin >> k;
            if (database.find(k) != database.end()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (cmd == "insert") {
            cin >> k;
            if (database.find(k) == database.end()) {
                cout << 1 << '\n';
                database.insert(k);
            }
            else {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
    
}
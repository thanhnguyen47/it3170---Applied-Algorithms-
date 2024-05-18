/*
Cho 2 số nguyên a và b, hãy tính tổng của 2 số đó.
Input:
    + Dòng 1 chứa 2 số nguyên a và b (0 <= a, b <= 10^19) --> unsigned long long
Output:
    + Ghi ra giá trị là tổng của a và b



*note: over flow: unsigned __int64: 0 to 18,446,744,073,709,551,615 (~ 18*1e18)
*/


#include <iostream>
using namespace std;


int main() {
    unsigned __int64 a, b;
    cin >> a >> b;
    unsigned __int64 a1, b1, a2, b2, c1, c2;

    a1 = a/10; b1 = b/10;
    a2 = a%10; b2 = b%10;
    
    c1 = a1 + b1 + (a2 + b2)/10;
    c2 = (a2 + b2)%10;

    if (c1 > 0) cout << c1 << c2;
    else cout << c2;
    return 0;
}
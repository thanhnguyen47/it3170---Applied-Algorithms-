#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 1000;

int n, b;
pii items[N]; // first is value and second is weight
// int cur;      // current value of the knapsack

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i].first >> items[i].second;
    }
}

// Greedy1: Sắp xếp các đồ vật theo thứ tự không tăng của giá trị
bool compare1(pii a, pii b)
{
    return (a.first > b.first);
}
// Greedy2: Sắp xếp các đồ vật theo thứ tự không giảm của trọng lượng
bool compare2(pii a, pii b)
{
    return a.second < b.second;
}

// Greedy3: Sắp xếp các đồ vật theo thứ tự không tăng của giá trị một đơn vị trọng lượng (Ci/Wi)
bool compare3(pii a, pii b)
{
    return 1.0 * a.first / a.second > 1.0 * b.first / b.second;
}

int greedy(int n, int b, pii items[], bool (*func_ptr)(pii, pii)) // sử dụng con trỏ hàm.
{
    int cur = 0;

    sort(items, items + n, func_ptr);

    for (int i = 0; i < n; ++i)
    {
        if (items[i].second <= b)
        {
            cur += items[i].first;
            b -= items[i].second;
        }
    }

    return cur;
}

// Greedy4: là max của một trong 3 lời giải trên. (lời giải tối ưu nhất tìm được )

int main()
{
    input();

    int f1 = greedy(n, b, items, compare1);
    int f2 = greedy(n, b, items, compare2);
    int f3 = greedy(n, b, items, compare3);

    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;
    cout << max(max(f1, f2), f3) << endl;

    return 0;
}
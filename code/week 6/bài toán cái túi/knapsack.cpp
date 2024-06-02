#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define MAX_N 1000

int n, b;
pii items[MAX_N]; // first is value and second is weight.

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i].first >> items[i].second;
    }
}

// sắp xếp theo thứ tự giá trị không tăng của đồ vật.
int greedy1()
{
    int curVal = 0, curWeight = b;
    sort(items, items + n, [](pii a, pii b)
         { return a.first < b.first; });

    for (int i = 0; i < n; ++i)
    {
        if (items[i].second < curWeight)
        {
            curVal += items[i].first;
            curWeight -= items[i].second;
        }
    }
    return curVal;
}

// sắp xếp theo thứ tự trọng lượng không giảm của đồ vật.
int greedy2()
{
    int curVal = 0, curWeight = b;
    sort(items, items + n, [](pii a, pii b)
         { return a.second > b.second; });

    for (int i = 0; i < n; ++i)
    {
        if (items[i].second < curWeight)
        {
            curVal += items[i].first;
            curWeight -= items[i].second;
        }
    }
    return curVal;
}

// sắp xếp theo thứ tự giá trị trên một đơn vị trọng lượng không tăng của đồ vật.
int greedy3()
{
    int curVal = 0, curWeight = b;
    sort(items, items + n, [](pii a, pii b)
         { return a.first / a.second > b.first / b.second; });

    for (int i = 0; i < n; ++i)
    {
        if (items[i].second < curWeight)
        {
            curVal += items[i].first;
            curWeight -= items[i].second;
        }
    }
    return curVal;
}

int greedy4()
{
    return max(max(greedy1(), greedy2()), greedy3());
}
int main()
{
    input();

    cout << greedy4();
}
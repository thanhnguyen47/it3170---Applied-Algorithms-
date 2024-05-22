#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000004

int n;
int arr[MAX_N];
int max_seq[MAX_N];
bool mark[MAX_N];

int maxSum(int i)
{
    if (i == 1)
        return arr[1];

    if (mark[i])
        return max_seq[i];

    int res = max(arr[i], arr[i] + maxSum(i - 1));
    mark[i] = true;
    max_seq[i] = res;

    return res;
}

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
}

void init() {
    max_seq[1] = arr[1];
    mark[1] =true;
}

void Trace(int);
void Trace2(int);
int main()
{

    input();
    init();

    int res = -1e9;
    int pos;
    for (int i = 1; i <= n; ++i)
    {
        // res = max(res, maxSum(i));
        int s = maxSum(i);
        if (res < s)
        {
            res = s;
            pos = i;
        }
    }
    cout << "Trace 1: ";
    Trace(pos);
    cout << '\n';
    cout << "Trace 2: ";
    Trace2(pos);
    cout << '\n';
    cout << res;
    return 0;
}

// làm thế nào biết được chính xác đoạn nào trong dãy tạo ra tổng lớn nhất tìm được.
// Truy vết bằng đệ quy, độ phức tạp: O(N)
void Trace(int i)
{
    if (i != 1 && max_seq[i] == arr[i] + max_seq[i - 1])
    {
        Trace(i - 1);
    }
    cout << arr[i] << ' ';
}

// Truy vết bằng vòng lặp
void Trace2(int i)
{
    int l = i;
    int sum = arr[l];
    while (sum != max_seq[i])
    {
        sum += arr[--l];
    }

    for (int j = l; j <= i; ++j)
    {
        cout << arr[j] << ' ';
    }
}
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define MAX_N 10000

int n;
pii jobs[MAX_N]; // {start, finish}

vector<pii> selectedJobs;

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> jobs[i].first >> jobs[i].second;
    }
}

bool check(pii a)
{
    for (auto b : selectedJobs)
    {
        if (!(a.first > b.second || b.first > a.second))
            return false;
    }
    return true;
}

/*
Chiến lược: sắp xếp các job (tập ứng cử viên) theo thứ tự job kết thúc sớm hơn xét trước.
*/
void greedy()
{
    sort(jobs, jobs + n, [](pii a, pii b)
         { return a.second < b.second; });

    for (int i = 0; i < n; ++i)
    {
        if (check(jobs[i]))
        {
            selectedJobs.push_back(jobs[i]);
        }
    }
}

int main()
{
    input();
    greedy();

    for (auto job : selectedJobs)
    {
        cout << job.first << ' ' << job.second << '\n';
    }
}
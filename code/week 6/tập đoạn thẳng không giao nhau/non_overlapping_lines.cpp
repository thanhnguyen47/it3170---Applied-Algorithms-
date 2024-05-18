#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define MAX_N 1000

int n;
pii jobs[MAX_N]; // {start, finish}

vector<pii> selectedJobs;

void input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> jobs[i].first >> jobs[i].second;
    }
}

bool compare(pii a, pii b)
{
    return a.second < b.second;
}

bool check(pii job_i)
{
    for (auto job : jobs)
    {
        if ((job.first < job_i.first && job_i.first < job.second) || (job.first < job_i.second && job_i.second < job.second))
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    sort(jobs, jobs + n, compare);

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

    solve();

    return 0;
}

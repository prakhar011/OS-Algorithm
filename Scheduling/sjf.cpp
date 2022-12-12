#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Process
{
public:
    int pid;
    int burst_time;
    int arrival_time;
    int st;
    int ct;
};

int main()
{
    int n;
    cout << "Enter number of processes : ";
    cin >> n;
    Process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i;
        cout << "Enter burst time and arrival time for process " << i+1 << " : ";
        cin >> p[i].burst_time >> p[i].arrival_time;
    }
    sort(p, p + n, [](Process a, Process b)
         { return a.arrival_time < b.arrival_time; });

                    //  burst time, arrival time, process id
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    int currentTime = p[0].arrival_time, i = 1;
    pq.push({p[0].burst_time, {p[0].arrival_time, p[0].pid}});
    while (!pq.empty())
    {
        int id = pq.top().second.second;
        int arrival = pq.top().second.first;
        int burst = pq.top().first;
        pq.pop();
        p[id].st = currentTime;
        p[id].ct = currentTime + burst;
        currentTime = currentTime + burst;
        while (i < n and p[i].arrival_time <= currentTime)
        {
            pq.push({p[i].burst_time, {p[i].arrival_time, p[i].pid}});
            i++;
        }
    }
    float responseTime = 0, waitingTime = 0;
    for (int i = 0; i < n; i++)
    {
        responseTime += p[i].st - p[i].arrival_time;
        waitingTime += p[i].ct - p[i].arrival_time - p[i].burst_time;
    }
    cout << "Avg response time: " << responseTime / n << endl;
    cout << "Avg waiting time: " << waitingTime / n << endl;

    return 0;
}

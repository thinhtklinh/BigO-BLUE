// ex8: The Lazy Programmer
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int w, dev, deadline;

    bool operator<(const Job& other) const {
        return w < other.w;
    }

    Job(int _w, int _b, int _d) : w(_w), dev(_b), deadline(_d) {};
};

bool sortByDeadline(const Job& a, const Job& b) {
    return a.deadline < b.deadline;
}

void ex8() {
    int tc, n, a, b, d;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<Job> jobs;
        priority_queue<Job> pq;
        while (n--) {
            cin >> a >> b >> d;
            jobs.push_back(Job(a, b, d));
        }

        sort(jobs.begin(), jobs.end(), sortByDeadline);
        double cost = 0;
        int time = 0;

        for (int i=0; i<jobs.size(); i++) {
            time += jobs[i].dev;
            pq.push(jobs[i]);

            while (time > jobs[i].deadline) {
                Job prio = pq.top();
                pq.pop();

                if (prio.dev > time - jobs[i].deadline) {
                    cost += (time - jobs[i].deadline) * 1.0 / prio.w;
                    prio.dev -= time - jobs[i].deadline;
                    pq.push(prio); // still reduce-able
                    time = jobs[i].deadline;
                }
                else {
                    cost += prio.dev*1.0/prio.w;
                    time -= prio.dev;
                    prio.dev = 0;
                }
            }
        }

        cout << setprecision(2) << fixed << cost << '\n';
        
        while (!pq.empty()) pq.pop();
        jobs.clear();
    }
}

int main() {
    ex8();
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Ferry Loading III -> O(C*M)
struct Car {
    int arrive;
    int id;

    // Car() {}
    Car(int a, int b) : arrive(a), id(b) {}
};

int main() {
    int tc;
    cin >> tc;
    int n, t, m;
    while (tc--) {
        cin >> n >> t >> m;
        queue<Car> cute[2];
        int time;
        string side;
        for (int i = 0; i < m; i++) {
            cin >> time >> side;
            if (side == "left")
                cute[0].push(Car(time, i));
            else
                cute[1].push(Car(time, i));
        }

        int curS = 0; // left
        int curT = 0;
        int nextT = 0;
        vector<int> ans(m);

        int waiting = (!cute[0].empty()) + (!cute[1].empty());

        while (waiting) {
            if (waiting == 2) {
                nextT = min(cute[0].front().arrive, cute[1].front().arrive);
            } else {
                if (cute[0].empty())
                    nextT = cute[1].front().arrive;
                else
                    nextT = cute[0].front().arrive;
            }
            curT = max(curT, nextT);
            int loaded = 0;
            while (!cute[curS].empty()) {
                Car ca = cute[curS].front();
                if (loaded < n && ca.arrive <= curT) {
                    loaded++;
                    cute[curS].pop();
                    ans[ca.id] = curT + t;
                } else
                    break;
            }

            curS = 1 - curS;
            curT += t;
            waiting = (!cute[0].empty()) + (!cute[1].empty());
        }

        for (int i = 0; i < m; i++) {
            cout << ans[i] << "\n";
        }
        if (tc) cout << endl;
    }
    return 0;
}
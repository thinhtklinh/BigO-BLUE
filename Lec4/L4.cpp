#include <deque>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void ex1() {
    int n;
    cin >> n;
    string exp;

    for (int i = 0; i < n; ++i) {
        cin >> exp;
        string res = "";
        stack<char> stac;

        for (int c = 0; c < exp.length(); ++c) {
            if (exp[c] == '(')
                ;
            else if (exp[c] == '+' || exp[c] == '-' || exp[c] == '*' || exp[c] == '/' || exp[c] == '^') {
                stac.push(exp[c]);
            } else if (exp[c] == ')') {
                if (stac.empty())
                    ;
                else {
                    res += stac.top();
                    stac.pop();
                }
            } else {
                // alpha
                res += exp[c];
            }
        }

        cout << res << '\n';
    }
}

// Ex2: Street Parade
void ex2() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        stack<int> stac;
        int pass = 1;
        int idx = 0;
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            cin >> idx;
            if (idx > pass) {
                stac.push(idx);
            } else {
                pass += 1;
                while (!stac.empty() && stac.top() == pass) {
                    stac.pop();
                    pass += 1;
                }
            }
        }
        while (!stac.empty()) {
            if (stac.top() != pass) {
                flag = 1;
                break;
            } else {
                stac.pop();
                pass += 1;
            }
        }

        if (flag)
            cout << "no\n";
        else
            cout << "yes\n";
    }
}

// Ex3: Throwing Cards Away I
void ex3() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        if (n == 1) {
            cout << "Discarded cards:\n";
            cout << "Remaining card: 1\n";
            continue;
        }
        queue<int> cute;
        for (int i = 1; i <= n; ++i)
            cute.push(i);
        string removed = "Discarded cards:";
        while (cute.size() > 2) {
            removed += " " + to_string(cute.front()) + ",";
            cute.pop();
            int card = cute.front();
            cute.push(card);
            cute.pop();
        }
        removed += " " + to_string(cute.front());
        cute.pop();
        int card = cute.front();
        cute.push(card);
        cute.pop();

        cout << removed << '\n';
        cout << "Remaining card: " << cute.front() << "\n";
    }
}

// Ex4: That is Your Queue
void ex4() {
    int p, c;
    int tc = 1;
    while (true) {
        cin >> p >> c;
        if (p == 0)
            break;
        cout << "Case " << tc << ":\n";
        tc++;

        int size = min(p, c);
        deque<int> pats;
        for (int i = 1; i <= size; ++i)
            pats.push_back(i);
        char cmd;
        for (int i = 0; i < c; i++) {
            cin >> cmd;
            if (cmd == 'N') {
                cout << pats.front() << '\n';
                pats.push_back(pats.front());
                pats.pop_front();
            } else {
                int tmp;
                cin >> tmp;
                bool flag = 0;
                int j = 0;
                while (j < pats.size()) {
                    if (pats[j] == tmp) {
                        flag = 1;
                        break;
                    }
                    j++;
                }
                if (flag) {
                    if (j != 0) {
                        pats.erase(pats.begin() + j);
                        pats.push_front(tmp);
                    }
                } else {
                    pats.push_front(tmp);
                }
            }
        }
    }
}

// Ex5: Mass of Molecule
void ex5() {
    string inp;
    cin >> inp;
    stack<int> stac;
    for (int c = 0; c < inp.length(); c++) {
        if (inp[c] == '(')
            stac.push(-1); // because '(' is 40 -> side effect
        else if (isdigit(inp[c])) {
            stac.top() *= (int(inp[c]) - 48);
        } else if (inp[c] == ')') {
            int submas = 0;
            while (stac.top() != -1) {
                submas += stac.top();
                stac.pop();
            }
            stac.pop();
            stac.push(submas);
        } else {
            // alpha
            int m;
            if (inp[c] == 'C')
                m = 12;
            else if (inp[c] == 'H')
                m = 1;
            else
                m = 16;
            stac.push(m);
        }
    }
    int mass = 0;
    while (!stac.empty()) {
        mass += stac.top();
        stac.pop();
    }
    cout << mass << endl;
}

// Ferry Loading III
void ex6_TLE() {
    int c;
    cin >> c;
    while (c--) {
        int n, t, m;
        cin >> n >> t >> m;
        queue<int> Lcute;
        queue<int> Rcute;
        int arrive;
        string side;
        for (int i = 0; i < m; ++i) {
            cin >> arrive >> side;
            if (side == "left")
                Lcute.push(arrive);
            else
                Rcute.push(arrive);
        }

        int time = 0;
        bool left = 1;
        int slot = n;
        while (true) {
            if (left) {
                while (slot && !Lcute.empty() && Lcute.front() <= time) {
                    Lcute.pop();
                    slot--;
                }
            } else {
                while (slot && !Rcute.empty() && Rcute.front() <= time) {
                    Rcute.pop();
                    slot--;
                }
            }

            if (slot != n) {
                time += t;
                left = 1 - left;

                while (slot != n) {
                    cout << time << '\n';
                    slot++;
                }
            } else {
                if (Rcute.empty() && Lcute.empty())
                    break;
                else if (!left) { // right side
                    if (!Rcute.empty() && Rcute.front() <= time)
                        ;
                    else if (!Lcute.empty() && Lcute.front() <= time) {
                        left = 1;
                        time += t;
                    } else {
                        // both > time
                        if (Rcute.front() < Lcute.front()) {
                            time = Rcute.front();
                        } else {
                            time = Lcute.front() + t;
                            left = 1;
                        }
                    }
                } else { // left side
                    if (!Lcute.empty() && Lcute.front() <= time)
                        ;
                    else if (!Rcute.empty() && Rcute.front() <= time) {
                        left = 0;
                        time += t;
                    } else {
                        // both > time
                        if (Lcute.front() < Rcute.front()) {
                            time = Lcute.front();
                        } else {
                            time = Rcute.front() + t;
                            left = 0;
                        }
                    }
                }
            }
        }
        if (c)
            cout << '\n';
    }
}

// Ex7: 
void ex7() {
    int n, maxQ;
    cin >> n >> maxQ;
    long long t, d;
    long long time = 0;
    queue<long long> cute;
    int cuteS = 0;
    // bool busy = 0;
    while (n--) {
        cin >> t >> d;
        if (t < time) {
            if (cuteS < maxQ) {
                cute.push(d);
                cuteS++;
            } else
                cute.push(-1);
        } else if (!cuteS) {
            time = t + d;
            cout << time << ' ';
        } else {
            // t >= time && cuteS > 0
            while (t >= time) {
                while (cute.front() == -1) {
                    cout << -1 << ' ';
                    cute.pop();
                }
                if (cuteS > 1) {
                    time += cute.front();
                    cout << time << ' ';
                    cute.pop();
                    cute.push(d);
                } else if (cuteS == 1) {
                    time += cute.front();
                    cout << time << ' ';
                    cute.pop();
                    cuteS--;
                    while (cute.front() == -1) {
                        cout << -1 << ' ';
                        cute.pop();
                    }
                    if (t > time) {
                        time = t + d;
                        cout << time << ' ';
                    } else {
                        cute.push(d);
                        cuteS++;
                    }
                } else {
                    time = t + d;
                    cout << time << ' ';
                }
            }
        }
    }
    while (!cute.empty()) {
        if (cute.front() == -1) {
            cout << -1 << ' ';
            cute.pop();
        } else {
            time += cute.front();
            cout << time << ' ';
            cute.pop();
        }
    }
}

// Ex8: Compilers and Parsers
void ex8() {
    int n;
    string inp;
    cin >> n;
    while (n--) {
        cin >> inp;
        int open = 0;
        int maxL = 0;
        // int curL = 0;
        for (int i = 0; i < inp.size(); ++i) {
            if (inp[i] == '<') {
                open++;
            } else {
                if (open) {
                    open--;
                    if (!open)
                        maxL = i + 1;
                } else {
                    break;
                }
            }
        }
        cout << maxL << '\n';
    }
}

int main() {
    ex6_TLE();
    return 0;
}
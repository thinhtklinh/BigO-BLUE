#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> hip;

void minHeapify (int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < hip.size() && hip[l] < hip[smallest]) smallest = l;
    if (r < hip.size() && hip[r] < hip[smallest]) smallest = r;
    if (smallest != i) {
        swap(hip[i], hip[smallest]);
        minHeapify(smallest);
    }

}

void buildHeap(int n) {
    for (int i=n/2-1; i > -1; i--) {
        minHeapify(i);
    }
}

int top() {
    return hip[0];
}

void push (int val) {
    hip.push_back(val);
    int i = hip.size() - 1;
    while (i && hip[(i-1)/2] > hip[i]) {
        swap(hip[i], hip[(i-1)/2]);
        i = (i-1)/2;
    }
}

void pop() {
    int len = hip.size();
    if (!len) return;
    hip[0] = hip[len-1];
    hip.pop_back();
    minHeapify(0); 
}

int main() {
    hip = {5, 1, 6, 34, 13, 66, 23, 21, 3};

    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;

    cout << int(-1/2) << '\n';
    return 0;
}
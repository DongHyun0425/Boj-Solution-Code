#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int G = 0;
int P = 0;

int parent[100003];

void init() {
    cin >> G;
    cin >> P;

    for (int i = 0; i < 100003; i++) {
        parent[i] = i;
    }
}

int find_parent(int x) {
    if (x != parent[x]) return parent[x] = find_parent(parent[x]);
    return x;
}

void merge(int a, int b) {
    int x = find_parent(a);
    int y = find_parent(b);

    parent[x] = y;
}

void solve() {
    int i = 0;
    for (i = 0; i < P; i++) {
        int tmp = 0;
        cin >> tmp;

        int idx = find_parent(tmp);
        if (idx != 0) merge(idx, idx - 1);
        else break;
    }
    cout << i;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();
    return 0;
}
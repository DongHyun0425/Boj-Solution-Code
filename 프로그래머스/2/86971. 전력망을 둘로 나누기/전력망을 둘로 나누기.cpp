#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int parent[101] = { 0, };
int result = 100000;
int nN = 0;

int ffind(int x) {
    if (parent[x] == x) return x;
    return parent[x] = ffind(parent[x]);
}

void check() {
    int a = ffind(1);
    int b = 0;
    for (int i = 2; i <= nN; i++) {
        if (ffind(i) != a) {
            b = ffind(i);
            break;
        }
    }

    int acnt = 0; int bcnt = 0;
    for (int i = 1; i <= nN; i++) {
        if (ffind(i) == a) acnt++;
        else {
            bcnt++;
        }
    }
    if (result > abs(acnt - bcnt)) {
        result = abs(acnt - bcnt);
    }
}


void merge(int N, int a) {
    int x = ffind(N);
    int y = ffind(a);

    if (x == y) {
        return;
    }
    else {
        parent[y] = x;
    }
}

void myinitiate() {
    for (int i = 0; i < 101; i++) {
        parent[i] = i;
    }
}

int solution(int n,vector<vector<int>> wires) {
    nN = n;
    myinitiate();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (cnt == j) continue;
            else {
                merge(wires[j][0], wires[j][1]);
            }
        }
        check();
        cnt++;
        myinitiate();
    }
    return result;
}

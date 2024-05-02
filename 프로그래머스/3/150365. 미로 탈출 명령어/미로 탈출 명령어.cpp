#include <string>
#include <vector>

using namespace std;

struct Delta {
    string command = "dlru";
    vector<int> dx {1, 0, 0, -1};
    vector<int> dy {0, -1, 1, 0};
};

bool OOB (int x, int y, int n, int m){
    if ( 0 < x && x <= n && 0 < y && y <= m){
        return true;
    }
    else {
        return false;
    }
}

void dfs(int x, int y, vector<int>& info, const Delta& delta, string& answer, string& stack, int depth, bool& dfsExit){
    if (dfsExit){
        return;
    }
    int n = info[0];
    int m = info[1];
    int r = info[2];
    int c = info[3];
    int k = info[4];

    if (k - depth < abs(x-r) + abs(y-c)){
        return;
    }

    // printf("x: %d, y: %d, depth: %d\n", x, y, depth);
    if (depth == k){
        if (x == r && y == c){
            // cout << stack << endl;
            answer = stack;
            dfsExit = true;
        }
        return;
    }
    
    for (int d=0; d < 4; d++){
        int nextX = x + delta.dx[d];
        int nextY = y + delta.dy[d];
        if (OOB(nextX, nextY, n, m)){
            stack += delta.command[d];
            dfs(nextX, nextY, info, delta, answer, stack, depth+1, dfsExit);
            stack = stack.erase(stack.size()-1);
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    string stack = "";
    vector<int> info {n, m, r, c, k};
    Delta delta;
    bool dfsExit = false;
    int remain = abs(x-r) + abs(y-c);
    if ((k - remain) % 2 != 0 || remain > k) {
        answer = "impossible";
    }
    else {
        dfs(x, y, info, delta, answer, stack, 0, dfsExit);
    }
    return answer;
}
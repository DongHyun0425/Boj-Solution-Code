#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int inode[1000010];
int onode[1000010];
vector <int> graph[1000010];
int root = 0;
vector<int> answer;
bool visited[1000010];

int eight = 0;
int mak = 0;
int donut = 0;

void BFS() {
    queue <int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node] = true;
        if (graph[node].size() >= 2 && node != root) {
            eight++;
        }
        else if (graph[node].size() == 0) {
            mak++;
        }
        else {
            for (int i = 0; i < graph[node].size(); i++) {
                if(!visited[graph[node][i]]) q.push(graph[node][i]);
            }
        }
    }

}

vector<int> solution(vector<vector<int>> edges) {
    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        onode[edges[i][0]]++;
        inode[edges[i][1]]++;
    }
    for (int i = 0; i < 1000010; i++) {
        if (onode[i] >= 2 && inode[i] == 0) {
            answer.push_back(i);
            root = i;
        }
    }
    BFS();
    donut = graph[root].size() - mak - eight;
    answer.push_back(donut);
    answer.push_back(mak);
    answer.push_back(eight);


    return answer;
}

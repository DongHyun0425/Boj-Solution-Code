#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> graph[17];
int answer = 0;

void DFS(int currentNode, int sheep, int wolf , queue<int> q, vector<int> &info){

    if (info[currentNode] == 0) {
        sheep++;
    } else {
        wolf++;
    }
    
    if(wolf>=sheep) return;
    if(answer < sheep) answer = sheep;

    //예제 1번->0번노드에서 1번,8번 노드 추가

    for(int i=0;i<graph[currentNode].size();i++){

        q.push(graph[currentNode][i]);

    }

    //만약 늑대가 sheep의 갯수보다 이상이면 그 뒤에 노드 탐색 필요 x
    if(wolf>=sheep){
        return ;
    }
    
    for(int i=0;i<q.size();i++){
        int next = q.front();
        q.pop();
        DFS(next,sheep,wolf,q,info);
        q.push(next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    //graph만들기
    for(int i=0;i<edges.size();i++){
        int parent = edges[i][0];
        int child = edges[i][1];
        graph[parent].push_back(child);
    }
    
    queue<int> q;
    DFS(0,0,0,q,info);
    return answer;
}
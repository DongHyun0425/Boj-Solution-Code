#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정
int n, m, start;

vector<pair<int, int> > graph[100001]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int d[100001]; // 최단 거리 테이블 만들기

void dijkstra(int start)
{
    priority_queue<pair<int, int>>pq; // 거리, 노드 인덱스

    pq.push({ 0,start }); //시작 노드로 가기위한 최단 경로는 0으로 설정하여, 큐에 삽입.
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first; //현재 노드까지의 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();

        if (d[now] < dist) // 이미 최단경로를 체크한 노드인 경우 패스
            continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = dist + graph[now][i].second; // 거쳐서 가는 노드의 비용을 계산
                                                  // 현재노드까지 비용 + 다음 노드 비용
            if (cost < d[graph[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int solution(int N, vector<vector<int>> edge) {
    n=N;
     for (int i = 0; i < edge.size(); i++)
    {
        // a번 노드에서 b번 노드로 가는 비용이 c라는 의미
        graph[edge[i][0]].push_back({ edge[i][1], 1 });
        graph[edge[i][1]].push_back({ edge[i][0], 1 });
    }
    fill(d, d + 100001, INF);
    dijkstra(1);
    int answer = 0;
    int max=0;
    for(int i=1;i<=N;i++){
        if(d[i]>max) max = d[i];
    }
    for(int i=1;i<=N;i++){
        if(d[i]==max) answer++;
    }
    return answer;
}
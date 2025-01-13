#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

// 노드의 개수(N), 간선의 개수(M), 도착 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정
int n, m, End;

vector<pair<int, int> > graph[100001]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int d[100001]; // 최단 거리 테이블 만들기

int answer[100001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>>pq; // 거리, 노드 인덱스

    pq.push({ 0,start }); //시작 노드로 가기위한 최단 경로는 0으로 설정하여, 큐에 삽입.
    d[start] = 0;

    while (!pq.empty())
    {
        int dist =  - pq.top().first; //현재 노드까지의 비용
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

int main(void)
{
    cin >> n >> m >> End;

    // 모든 간선 정보를 입력받기
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // a번 노드에서 b번 노드로 가는 비용이 c라는 의미
        graph[a].push_back({ b, c });
    }

    // 최단 거리 테이블을 모두 무한으로 초기화
    fill(d, d + 100001, INF);


    // 다익스트라 알고리즘을 수행
    for (int i = 1; i <= n; i++) {
        //1번노드부터 모든 노드까지 최단거리
        if (i != End) {
            dijkstra(i);
            answer[i] += d[End];
        }
        else {
           //End부터 집으로 돌아갈때의 최단거리
            dijkstra(i);
            for (int j = 1; j <= n; j++) {
                answer[j] += d[j];
            }
        }
        fill(d, d + 100001, INF);
    }

    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (max < answer[i]) max = answer[i];
    }
    cout << max;
}
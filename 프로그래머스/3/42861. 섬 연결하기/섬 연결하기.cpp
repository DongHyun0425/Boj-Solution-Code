#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int parent[101]={0,};
vector <pair<int,pair<int,int>>>cost;

int findparent(int x){
    if (parent[x] == x) return x;
    return parent[x] = findparent(parent[x]);
}

void merge(int N, int a) {
    int x = findparent(N);
    int y = findparent(a);

    if (x == y) {
        return;
    }
    else if(x > y){
        parent[x] = y;
    }
    else 
    {
        parent[y] = x;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<costs.size();i++){
        cost.push_back({costs[i][2],{costs[i][0],costs[i][1]}});
    }
    sort(cost.begin(),cost.end());
    
    for(int i=0;i<100;i++){
        parent[i]=i;
    }
 
    for(int i=0;i<cost.size();i++){
        if(findparent(cost[i].second.first)!=findparent(cost[i].second.second)){
            answer+=cost[i].first;
            merge(cost[i].second.first,cost[i].second.second);
        }
    }
    
    return answer;
}
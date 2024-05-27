#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long graph[201][201];

int solution(int n, int S, int A, int B, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i=0;i<201;i++){
        for(int j=0;j<201;j++){
            if(i==j){graph[i][j]=0;}
            else{
            graph[i][j]=8*1e10;
            }
        }
    }
    
    for(int i=0;i<fares.size();i++){
        int a = fares[i][0];
        int b = fares[i][1];
        int cost = fares[i][2];
        graph[a][b]=cost;
        graph[b][a]=cost;
    }
    
    for(int k=1;k<=n;k++){
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                graph[a][b]=min(graph[a][b],graph[a][k]+graph[k][b]);
            }
        }
    }
    
    
    
    long long max = graph[S][A]+graph[S][B];
    
    for(int i=1;i<=n;i++){
        long long tmp = graph[S][i] + graph[i][A]+graph[i][B];
        if(tmp<max) max = tmp;
    }
    
    return max;
}
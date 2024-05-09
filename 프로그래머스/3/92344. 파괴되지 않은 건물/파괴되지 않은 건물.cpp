#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long map[1001][1001];
long long addmap[1001][1001];
int M = 0;
int N = 0;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    M=board.size();
    N=board[0].size();
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            map[i+1][j+1]=board[i][j];
        }
    }
    
    for(int i=0;i<skill.size();i++){
        int type = skill[i][0];
        int x1 = skill[i][1]+1;
        int y1 = skill[i][2]+1;
        int x2 = skill[i][3]+1;
        int y2 = skill[i][4]+1;
        int degree = skill[i][5];
        
        if(type == 1) degree = -degree;
        
        addmap[x1-1][y1-1] += degree;
        addmap[x2][y1-1] += -degree;
        addmap[x2][y2] += degree;
        addmap[x1-1][y2] += -degree;
    }
    
    
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            addmap[i][j+1]+=addmap[i][j];
        }
    }
    
    for(int i=0;i<1000;i++){
       for(int j=0;j<1000;j++){
            addmap[i+1][j]+=addmap[i][j];
        }
    }
    
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            map[i][j]+=addmap[i-1][j-1];
        }
    }
    
    
     for(int i=1;i<=M;i++){
        for(int j=1; j<=N;j++){
            if(map[i][j]>0) answer++;
        }
    }

    return answer;
}
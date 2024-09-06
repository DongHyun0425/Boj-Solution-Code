#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Data{
    int x;
    int y;
    int direction;
    int s;
    int c;
};

struct sc{
    int s;
    int c;
};

int m_size=0;
int map[25][25];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
sc cost[25][25][4];
queue <Data> q;
void BFS(){
    Data d = {0,0,-1,0,0};
    q.push(d);
    while(!q.empty()){
        Data d = q.front();
        q.pop();
        int x = d.x;
        int y = d.y;
        int direction = d.direction;
        int s = d.s;
        int c = d.c;
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<m_size && ny>=0 && ny<m_size && map[nx][ny]!=1){
                int ns =0; int nc=0; int nd=0;
                //처음 시작점에서 오른쪽,아래이동
                if(direction==-1 && i==0){
                    nd=0;
                    ns=s+1;
                    nc=c;
                }else if(direction==-1 && i==1){
                    nd=1;
                    ns=s+1;
                    nc=c;
                }else{
                    //현재 이동방향과 다르면 무조건 코너처리,이전 좌표로 이동해도 ns가 늘어나서 어차피 큐에 안드감
                    if(direction!=i){
                        nd=i;
                        ns=s+1;
                        nc=c+1;
                    }else{
                        //직선처리
                        nd=i;
                        ns=s+1;
                        nc=c;
                    }
                }
                sc temp = cost[nx][ny][nd];
                int n_s = temp.s;
                int n_c = temp.c;
                
                int n_total = n_s*100+n_c*500;
                int c_total = ns*100+nc*500;
                if(c_total<=n_total){
                    Data d = {nx,ny,nd,ns,nc};
                    sc t ={ns,nc};
                    cost[nx][ny][nd]=t;
                    q.push(d);
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {

    m_size=board.size();
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            map[i][j] = board[i][j];
        }
    }
    
    sc t ={1000,10000};
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            for(int k=0;k<4;k++){
                cost[i][j][k] = t;
            }
        }
    }
    sc tt ={0,0};
    cost[0][0][0]=tt;
    cost[0][0][1]=tt;
    cost[0][0][2]=tt;
    cost[0][0][3]=tt;
    BFS();
    int ttt=100000000;
    for(int i=0;i<4;i++){
        sc answer = cost[m_size-1][m_size-1][i];
        int t=answer.s*100+answer.c*500;
        if(ttt>t){
            ttt=t;
        }
    }
    return ttt;
}
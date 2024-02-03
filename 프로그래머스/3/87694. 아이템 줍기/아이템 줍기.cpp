#include <string>
#include <vector>

using namespace std;
 int map[101][101]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int result=123142;
int visited[101][101]={0,};
void dfs(int cx,int cy, int ix, int iy,int cnt){
    if(cx==ix&&cy==iy){
        if(result>cnt){
            result=cnt;
            return;
        }
    }
    
    for(int i=0;i<4;i++){
        int nx = cx+dx[i];
        int ny = cy+dy[i];
        if(map[nx][ny]==1&&visited[nx][ny]==0){
            visited[nx][ny]=1;
            dfs(nx,ny,ix,iy,cnt+1);
            visited[nx][ny]=0;
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for(int i=0;i<rectangle.size();i++){
        for(int x1=rectangle[i][0]*2;x1<=rectangle[i][2]*2;x1++){
            for(int y1=rectangle[i][1]*2;y1<=rectangle[i][3]*2;y1++){
                map[x1][y1]=1;
            }
        }
    }
    
    for(int i=0;i<rectangle.size();i++){
        for(int x1=rectangle[i][0]*2+1;x1<=rectangle[i][2]*2-1;x1++){
            for(int y1=rectangle[i][1]*2+1;y1<=rectangle[i][3]*2-1;y1++){
                map[x1][y1]=0;
            }
        }
    }
    
    dfs(characterX*2, characterY*2,itemX*2, itemY*2,0);
    return result/2;
}
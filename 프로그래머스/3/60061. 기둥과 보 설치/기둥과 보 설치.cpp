#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool column[101][101];
bool bar[101][101];

bool checkcolumn(int x, int y){
    //1번, 바닥인경우
    if(y==0) return true;
    //2번 아래에 기둥이 있는경우
    if(column[x][y-1]) return true;
    //3번 왼쪽에 보가 있는경우
    if(x-1>=0 && bar[x-1][y]) return true;
    //4번 오른쪽에 보가 있는경우
    if(bar[x][y]) return true;
    
    return false;
}

bool checkbar(int x, int y ){
    //1번 기둥위치에서 오른쪽으로 ㅣ -> ㅡ 
    if(column[x][y-1]) return true;
    //2번 기역자 ㄱ
    if(x+1<=100 && column[x+1][y-1]) return true;
    //3번 ㅡㅡㅡ 보보보
    if(x-1>=0 && bar[x-1][y] && x+1<=100 && bar[x+1][y]){ cout<<"hei";return true;}
    
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(int i=0;i<build_frame.size();i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int type = build_frame[i][2];
        int cmd = build_frame[i][3];
        
        if(type==0){
            if(cmd==1 && checkcolumn(x,y)){
                cout<<"make column"<<x<<" "<<y<<"\n";
                column[x][y]=true;
            }
            if(cmd==0){
                column[x][y]=false;
                //if문으로 기둥을 지웠을때 확인해야하는요소
                if(y+1<=100 && column[x][y+1] && !checkcolumn(x,y+1)){
                    cout<<"option 1"<<" ";
                    column[x][y]=true;
                }else if(y+1<=100 && bar[x][y+1] && !checkbar(x,y+1)){
                  cout<<"option 2"<<" ";
                    column[x][y]=true;
                }else if(x-1>=0 && y+1<=100 && bar[x-1][y+1] && !checkbar(x-1,y+1)){
                    cout<<"option 3"<<" ";
                    column[x][y]=true;
                }
            }
        }
        
        if(type==1){
            if(cmd==1 && checkbar(x,y)){
                cout<<"make bar"<<x<<" "<<y<<"\n";
                bar[x][y]=true;
            }
            if(cmd==0){
                bar[x][y]=false;
                //if문으로 보을 지웠을때 확인해야하는요소
                if(column[x][y] && !checkcolumn(x,y)){
                    cout<<"option 1"<<" ";
                    bar[x][y]=true;
                }else if(x+1<=100 && column[x+1][y] && !checkcolumn(x+1,y)){
                    cout<<"option 2"<<" ";
                    bar[x][y]=true;
                }else if(x-1>=0 && bar[x-1][y] && !checkbar(x-1,y)){
                    cout<<"option 3"<<" ";
                    bar[x][y]=true;
                }else if(x+1<=100 && bar[x+1][y] && !checkbar(x+1,y)){
                    cout<<"option 4"<<" ";
                    bar[x][y]=true;
                }
                 if(bar[x][y]==false) cout<<"bar"<<x<<" "<<y<<"delete"<<"\n";
            }
        }
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(column[i][j]){
                answer.push_back({i,j,0});
            }
            if(bar[i][j]){
                answer.push_back({i,j,1});
            }
        }
    }
        
    return answer;
}
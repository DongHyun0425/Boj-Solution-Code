#include <string>
#include <vector>
#include <queue>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int N;

struct Pos{
    int y;
    int x;
    int dir;
};

struct Robot{
    Pos part1;
    Pos part2;
    int time;
};

bool possible(vector<vector<int>> board, Pos part1, Pos part2){
    if(part1.y < 0 || part1.y>=N || part1.x <0 || part1.x >=N 
       ||part2.y < 0 || part2.y>=N || part2.x <0 || part2.x >=N)
        return false;
    //두위치가 벽이 아니어야함
    if(board[part1.y][part1.x]==1 || board[part2.y][part2.x]==1)
        return false;
    
    //벽도아니고 map 벗어 나지도 않음
    return true;
    
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    
    queue<Robot>q;
    
    //기준축을 기준으로 동서남북
    bool checked[100][100][4]={false};
    
    //로봇 처음
    Robot start{{0,0,LEFT}, {0,1,RIGHT},0};
    checked[0][0][LEFT]=true;
    checked[0][1][RIGHT] = true;
    q.push(start);
    
    while(!q.empty()){
        Robot now = q.front();
        q.pop();
        
        //로봇이 목적지 방문시 return
        if(now.part1.y == N-1 && now.part1.x == N-1 || now.part2.y == N-1 && now.part2.x == N-1){
            answer = now.time;
            break;
        }
        
        //이동
        for(int i=0;i<4;i++){
            Pos next_part_1{now.part1.y + dy[i], now.part1.x + dx[i],now.part1.dir};
            Pos next_part_2{now.part2.y + dy[i], now.part2.x + dx[i],now.part2.dir};
            
            //일단 다음 이동 위치에 1이 있는지 없는지
            if(!possible(board,next_part_1,next_part_2))
                continue;
            //이미 방문한적이 있는지 판단하는 if문
            if(checked[next_part_1.y][next_part_1.x][next_part_1.dir] && checked[next_part_2.y][next_part_2.x][next_part_2.dir])
                continue;
            
            Robot next{next_part_1,next_part_2,now.time+1};
            q.push(next);
            checked[next.part1.y][next.part1.x][next.part1.dir] = true;
            checked[next.part2.y][next.part2.x][next.part2.dir]= true;
        }
        
        //회전 영역
        //현재 로봇이 ㅡ로 있고 왼쪽이 회전축 인경우
        if(now.part1.dir==LEFT){
            //1.위로 회전할떄 필요한 공간
            Pos up_left{now.part1.y-1, now.part1.x, UP};
            Pos up_right{now.part2.y-1, now.part2.x, UP};
            
            //회전할때 필요한 공간 둘다 1이 아닌경우
            if(possible(board,up_left,up_right)){
                //1-1. 왼쪽 축을 기준으로 위로 회전
                //둘다 true인경우만 불가은 false true, true false 이런건 가능
                if(!checked[up_left.y][up_left.x][UP] || !checked[now.part1.y][now.part1.x][DOWN]){
                    q.push({up_left, {now.part1.y,now.part1.x,DOWN},now.time+1});
                    checked[up_left.y][up_left.x][UP] = true;
                    checked[now.part1.y][now.part1.x][DOWN] = true;
                }
                
                //1-2오른쪽 축을 기준으로 위로 회전
                if(!checked[up_right.y][up_right.x][UP] || !checked[now.part2.y][now.part2.x][DOWN]){
                    q.push({up_right, {now.part2.y,now.part2.x,DOWN},now.time+1});
                    checked[up_right.y][up_right.x][UP] = true;
                    checked[now.part2.y][now.part2.x][DOWN] = true;
                }
            }
            //2. 아래로 회전
            Pos down_left{now.part1.y + 1, now.part1.x, DOWN};
            Pos down_right{now.part2.y+1,now.part2.x,DOWN};
            
            if(possible(board, down_left, down_right)){
                //2-1. 왼쪽을 축 아래로 회전
                if(!checked[down_left.y][down_left.x][DOWN] || !checked[now.part1.y][now.part1.x][UP]){
                    q.push({{now.part1.y,now.part1.x,UP},down_left,now.time+1});
                    checked[down_left.y][down_left.x][DOWN] = true;
                    checked[now.part1.y][now.part1.x][UP] = true;
                }
                
                //2-2 오른쪽을 축으로 아래로 회전
                if(!checked[down_right.y][down_right.x][DOWN] || !checked[now.part2.y][now.part2.x][UP]){
                    q.push({{now.part2.y,now.part2.x,UP},down_right,now.time+1});
                    checked[down_right.y][down_right.x][DOWN] = true;
                    checked[now.part2.y][now.part2.x][UP] = true;
                }
            }
        }
        
        //로봇이 현재 ㅣ로 놓여있는경우
        if(now.part1.dir == UP){
            //1. 왼쪽으로 회전
            Pos left_up{now.part1.y,now.part1.x-1,LEFT};
            Pos left_down{now.part2.y,now.part2.x-1,LEFT};
            if(possible(board,left_up,left_down)){
                //1-1 위쪽을 축으로 왼쪽으로 회전
                if(!checked[left_up.y][left_up.x][LEFT] || !checked[now.part1.y][now.part1.x][RIGHT]){
                    q.push({left_up,{now.part1.y,now.part1.x,RIGHT},now.time+1});
                    checked[left_up.y][left_up.x][LEFT] = true;
                    checked[now.part1.y][now.part1.x][RIGHT] = true;
                }
                
                //1-2. 아래쪽을 축으로 왼쪽으로 회전
                if(!checked[left_down.y][left_down.x][LEFT] || !checked[now.part2.y][now.part2.x][RIGHT]){
                    q.push({left_down,{now.part2.y,now.part2.x,RIGHT},now.time+1});
                    checked[left_down.y][left_down.x][LEFT] =true;
                    checked[now.part2.y][now.part2.x][RIGHT] = true;
                }
            }
            
            //오른쪽ㅇ으로 회전
            Pos right_up{now.part1.y, now.part1.x+1,RIGHT};
            Pos right_down{now.part2.y,now.part2.x+1,RIGHT};
            if(possible(board,right_up,right_down)){
                //2-1 위쪽을 추긍로 오른쪽으로 회전
                if(!checked[right_up.y][right_up.x][RIGHT] || !checked[now.part1.y][now.part1.x][LEFT]){
                    q.push({{now.part1.y,now.part1.x,LEFT},right_up,now.time+1});
                    checked[right_up.y][right_up.x][RIGHT] = true;
                    checked[now.part1.y][now.part1.x][LEFT] = true;
                }
                //2-2 아래쪽을 축으로 오른쪽으로 회전
                 if (!checked[right_down.y][right_down.x][RIGHT] || !checked[now.part2.y][now.part2.x][LEFT]) {
                    q.push({ { now.part2.y, now.part2.x, LEFT } , right_down, now.time + 1 });
                    checked[right_down.y][right_down.x][RIGHT] = true;
                    checked[now.part2.y][now.part2.x][LEFT] = true;
                }
            }
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
//좌표
struct Point{
    int x;
    int y;
};

vector<vector<bool>> check; // 방문 처리
vector<vector<Point>> puzzleList; // 퍼즐을 담는 리스트
vector<vector<Point>> emptyList;//빈공간을 담는 리스트


//퍼즐 추출하는함수
//파라미터에서 sx,sy는 현재 퍼즐 뭉텅이에서 첫 조각
//select로 설정한이유는? 그냥 puzzles라하지??
vector<Point> getPuzzle(int sx,int sy,vector<vector<bool>>select){
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    
    //queue는 bfs로 탐색을 위한것이고
    queue<Point> q;
    //list는 퍼즐 뭉치에서 좌표들이 들어가는것이다. 5번 조각같은경우 {{0,0},{0,1}} 이렇게 list에 들어가고 이 list가 나중에는 반환되어서 puzzleList에 들어가는데 {{{0,0},{0,1}},,,,}이런식으로 표시될것이다.
    vector<Point> list;
    //퍼즐 뭉텅이 조각에서 첫번째 조각 방문처리
    check[sx][sy]=true;
    Point p={sx,sy};
    q.push(p);
    list.push_back(p);
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            //map에서 벗어나고, 방문을 했거나, table에서 0이면 패스
            if(nx<0 || ny<0||nx>=select.size() || ny>=select.size() || check[nx][ny] || !select[nx][ny]) continue;
            check[nx][ny]=true;
            Point np = {nx,ny};
            q.push(np);
            list.push_back(np);
        }
    }
    cout<<list.size()<<"\n";
    return list;
}

vector<Point> rePos(vector<Point> p){
    int minX = p[0].x;
    int minY = p[0].y;
    
    //그 모양 뭉텅이 1개에서 제일 작은 좌표 찾기
    for(int i=1;i<p.size();i++){
        minX = min(minX,p[i].x);
        minY = min(minY,p[i].y);
    }
    //제일 작은 좌표를 찾고 그 좌표를 빼줌, ex{1,1},{1,2}라면 1,1을 빼주면 시작좌표 {0,0},{0,1}일테니까, 결국 0,0시작인거임
    for(int i=0;i<p.size();i++){
        p[i].x-=minX;
        p[i].y-=minY;
    }
    return p;
}

//빈공간의 모양과 puzzle의 모양이 동일한지 확인
int comparePuzzle(vector<Point> a, vector<Point> b){
    int answer =0;
    //현재 좌표값이 다르므로, 맨왼쪽을 0,0으로 만들어서 비교해줘야함
    a = rePos(a);
    b = rePos(b);
    
    int count =0;
    //애초에 size가다르면 비교 할 이유 x
    if(a.size() !=b.size()) return 0;
    
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i].x==b[j].x && a[i].y==b[j].y){
                //좌표가 동일하다면, count++하고 break; 뒤에꺼 더 살펴볼 이유가 없으니까.
                count++;
                break;
            }
        }
    }
    //일치하는 좌표의 갯수가 동일해야지만 맞음
    if(count == a.size()) return a.size();
    else return 0;
}

//메꿔야하는 빈공간 뭉텅이의 좌표를 가져와서 board[x][y]=false로 바꾸기 현제 board에는 빈공간이 0임.
vector<vector<bool>> fillBoard(vector<Point> p,vector<vector<bool>> board){
    for(int i=0;i<p.size();i++){
        int x = p[i].x;
        int y =p[i].y;
        board[x][y]=false;
    }
    return board;
}

//board를 자체를 90도 돌리기
vector<vector<bool>> rotateOnce(vector<vector<bool>> origin){
    int c = origin.size();
    int r = origin.size();
    
    //새롭게 반환할 90도가 돌아간 보드판
    vector<vector<bool>> board;
    vector<bool> row(r);
    
    for(int i=0;i<c;i++) board.push_back(row);
    
    //90도 돌리는 작업
    for(int i=0;i<origin.size();i++){
        for(int j=0;j<origin[i].size();j++){
            board[origin.size()-j-1][i] = origin[i][j];
        }
    }
    return board;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    vector<vector<bool>> board;
    vector<vector<bool>> puzzles;
    for(int i=0; i < table.size();i++){
        vector<bool>v1; //보드에서 채워야하는 부분이 들어감
        vector<bool>v2;
        vector<bool>v3;
        for(int j=0;j<table[i].size();j++){
            v1.push_back(!game_board[i][j]);//보드에서 0인부분이 1로 들어가게됨
            v2.push_back(table[i][j]);//table 자체를 복사
            v3.push_back(false);//v3에는 map을 전부 false로 채움
            
        }
        board.push_back(v1); //현재 board는 game_board의 반대가 들어가있음
        puzzles.push_back(v2);//현재 puzzle은 table자체를 복사
        check.push_back(v3);//map에서 false로 채운게 들어가있음
    }
   
    cout<<"퍼즐"<<"\n";
    for(int i=0;i<puzzles.size();i++){
        for(int j=0;j<puzzles[i].size();j++){
            //퍼즐을 돌면서 그 퍼즐 뭉텅이에 방문을 하지 않았고 , puzzles의 첫번째가 그 1이라면, puzzleList에다가  넣는다.
            if(!check[i][j] && puzzles[i][j]) puzzleList.push_back(getPuzzle(i,j,puzzles));
        }
    }
    
    //현재 퍼즐 덩이들 puzzleList에 담는거까지함
    //count가 4인 이유는 board를 90도씩 4번돌려야하기 때문이다.
    int count = 4;
    int answer = 0;
    //check를 다시 false로 채워넣음
    fill(check.begin(),check.end(),vector<bool>(check.size(),false));
    
    //1. 매회전 마다 빈공간 추출,
    //2. 그 값을 comparePuzzle과 비교하여 일치하면 블록 갯수반환
    //3. fillBoard를 통해 일치했던 블록의 좌표를 가져와 빈 공간을 메워주고
    //4. puzzleList와 emptyList에서 지운다.
    while(count--){
        cout<<"빈공간"<<"\n";
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board.size();j++)
                if(board[i][j] && !check[i][j])
                    //getPuzzle함수에 인자를 board를 넘겨주었으므로, board(현재 board는 위에서 반대로 거꾸로 넣어준)에서 1인 빈공간이 emptyList에 들어가게된다.
                    emptyList.push_back(getPuzzle(i,j,board));
        
        for(int i=0;i<puzzleList.size();i++){
            for(int j=0;j<emptyList.size();j++){
                //퍼즐리스트에있는 퍼즐과,emptyList의 빈공간비교, 그럼 여기까지오면, 어? 근데 그럼 좌표가 다른데? 싶을수있다.     
                int val = comparePuzzle(puzzleList[i],emptyList[j]);
                //val이 0이 아니여야 동일한 뭉텅이임, 고로 val이 0 이아니면 동일한 뭉텅이니까, puzzleList,emptyList에서 빼주고, 보드를 메꿔줘야함
                if(val !=0){
                    //answer에는 메꾼 빈공간 크기가 들어가있음
                    answer +=val;
                    //퍼즐과 동일한 빈공간 뭉텅이들의 좌표와, board판을 인자로 넘겨준다.
                    board = fillBoard(emptyList[j],board);
                    puzzleList.erase(puzzleList.begin()+i);
                    emptyList.erase(emptyList.begin()+j);
                    //여기서i--가중요한데 그이유는 puzzleListsize가 줄었기 떄문에 i값도 하나 줄여줘야한다는 점이다. 그럼 어? emptyList는 안줄여? break를 걸면 다시 첫번째 for문으로 돌아가기때문에 두번째 for문을 만날때는 새롭게 1개가 줄어든 emptyList.size()이기 떄문에 따로j--를해주지않아도 된다.
                    i--;
                    break;
                }
            }
        }
        //board자체를 한바퀴 돌리기
        board = rotateOnce(board);
        //check를 다시 false로 바꾸기, 그래야 다음번 while문에서 방문이 가능하니까
        fill(check.begin(),check.end(),vector<bool>(check.size(),false));
        cout<<"turn"<<"\n";
    }
    return answer;
}
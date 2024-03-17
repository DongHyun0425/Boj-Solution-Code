#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
vector<int> mygraph[31];
 int board_size = 0;

void makegraph(vector<vector<int>> &board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            int tmp = board[j][i];
            if(tmp>0){
                mygraph[i+1].push_back(board[j][i]);
            }
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> graph[31];
    board_size = board.size();
    
    makegraph(board);
    
    stack <int> s;
    for(int i=0;i<moves.size();i++){
        int t = moves[i];
        if(mygraph[t].size()>0){
           int tmp = mygraph[t][0];
           mygraph[t].erase(mygraph[t].begin());
            s.push(tmp);
            if(s.size()>1){
                int t1=s.top();
                s.pop();
                int t2 = s.top();
                if(t1==t2){
                    answer++;
                    answer++;
                    s.pop();
                }else{
                    s.push(t1);
                }            
            }
        }
    }
    
    return answer;
}
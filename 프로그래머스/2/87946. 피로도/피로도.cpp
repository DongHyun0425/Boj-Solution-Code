#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dungeon;
vector<pair<int,int>>v;
bool visited[9]={false,};
int N = 0;
int K=0;
int answer=-1;

void permutation(){
    if(v.size()==N){
        //순서대로 꺼내서 피로도 확인
        int total = K;
        int tmp =0;
        for(int i=0;i<v.size();i++){
            int need = v[i].first; //필요한 소모도
            int consume = v[i].second; //사용될 소모도
            
            if(total>=need){
                tmp++;
                total-=consume;
            }else break;
        }
        if(answer<tmp) answer = tmp;
    }
    
    //여기서부터 순열 코드
    for(int i=0;i<N;i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back({dungeon[i][0],dungeon[i][1]});
            permutation();
            v.pop_back();
            visited[i] = false;
        } 
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    //초기화
    N = dungeons.size();
    K = k;
    for(int i=0;i<dungeons.size();i++){
        dungeon.push_back(dungeons[i]);
    }
    
    permutation();
    
    return answer;
}
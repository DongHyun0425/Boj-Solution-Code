#include <string>
#include <vector>

using namespace std;

int Answer=0;
bool isLightOn[100001];
vector<int> info[100001];
int N = 0;

void dfs(int current, int parent){
    for(int i=0;i<info[current].size();i++){
        int next = info[current][i]; //5
        if(parent != next){
            dfs(next,current);
            if(!isLightOn[next] && !isLightOn[current]){
                isLightOn[current] = true;
                Answer++;
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> lighthouse) {
    N=n;
    for(int i=0;i<lighthouse.size();i++){
        info[lighthouse[i][0]].push_back(lighthouse[i][1]);
        info[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }
    
    dfs(1,1);
    return Answer;
}
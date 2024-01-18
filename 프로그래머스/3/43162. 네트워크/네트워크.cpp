#include <string>
#include <vector>

using namespace std;
int parent[200]={0,};

int myfind(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=myfind(parent[x]);
}

void merge(int pp,int child){
    pp=myfind(pp);
    child=myfind(child);
    if(pp==child) return;
    parent[child]=pp;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<200;i++){
        parent[i]=i;
    }
    for(int i=0;i<computers.size();i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            if(computers[i][j]==1){
                temp.push_back(j);
            }
        }
        for(int x=0;x<temp.size()-1;x++){
            merge(temp[x],temp[x+1]);
        }
    }
    
    for(int i=0;i<n;i++){
        if(myfind(i)==i){
            answer++;
        }
    }
    
    return answer;
}
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int targetr=0;
string answer="";
int targetc=0;
int flag =0;
int N=0;
int M=0;
int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
char addstring[4]={'d','l','r','u'};

void dfs(int x, int y ,int cnt,int k,string s){
    if(flag){
        return;
    }
    if(k-cnt<abs(x-targetr)+abs(y-targetc)){
        return;
    }
    
    if(cnt==k){
        if(x==targetr && y == targetc ){
        flag++;
        answer+=s;
        }
        return;
    }
    
    
    for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=1 && nx<=N && ny>=1 && ny <=M){
                s+=addstring[i];
                dfs(nx,ny,cnt+1,k,s);
                s.pop_back();
            }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N=n;
    M=m;
    targetr = r;
    targetc = c;
    int remain = abs(x-r)+abs(y-c);
    if((k-remain) % 2!=0 || remain > k){
       answer = "impossible"; 
    }else{
        string s="";
        dfs(x,y,0,k,s);
    }
    return answer;
}
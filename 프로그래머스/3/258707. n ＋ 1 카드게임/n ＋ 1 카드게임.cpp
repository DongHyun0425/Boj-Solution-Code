#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int target;

int findidx(vector<int>&v,int target){
    return find(v.begin(),v.end(),target)-v.begin();
}

bool canmake(vector<int>&v){
    int size=v.size();
    for(int i=0;i<size;i++){
        int t=target-v[i];
        if(find(v.begin(),v.end(),t)!=v.end()){
            v.erase(v.begin()+findidx(v,t));
            v.erase(v.begin()+i);
            return true;
        }
    }
    return false;
}

bool canmake2(vector<int>&v1,vector<int>&v2){
    for(int i=0;i<v1.size();i++){
        int t=target-v1[i];
        if(find(v2.begin(),v2.end(),t)!=v2.end()){
            v2.erase(v2.begin()+findidx(v2,t));
            v1.erase(v1.begin()+i);
            return true;
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    
    N=cards.size();
    
    vector<int> myhand;
    vector<int> tmp;
    for(int i=0;i<N/3;i++){
        myhand.push_back(cards[i]);
    }
    
    int cidx = N/3;
    target = N+1;
    
    while(cidx<N-1){
        tmp.push_back(cards[cidx]);
        tmp.push_back(cards[cidx+1]);
        cidx+=2;
        
        if(myhand.size()>=2&&canmake(myhand)){
            answer++;
        }else if(myhand.size()>=1 && coin>=1 && tmp.size()>=1 && canmake2(myhand,tmp)){
            answer++;
            coin--;
        }else if (tmp.size()>=2 && coin>=2 && canmake(tmp)){
            answer++;
            coin-=2;
        }else{
            break;
        }
    }
    return answer;
}
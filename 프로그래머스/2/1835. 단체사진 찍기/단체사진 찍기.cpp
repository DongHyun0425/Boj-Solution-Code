#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int answer = 0;
vector<string> Data;
vector<char> condition[101];
int N=0;
vector<char> v;
void init(){
    for(int i=0;i<N;i++){
        condition[i].push_back(Data[i][0]);
        condition[i].push_back(Data[i][2]);
        condition[i].push_back(Data[i][3]);
        condition[i].push_back(Data[i][4]);
    }
    v.push_back('A');
    v.push_back('C');
    v.push_back('F');
    v.push_back('J');
    v.push_back('M');
    v.push_back('N');
    v.push_back('R');
    v.push_back('T');
    sort(v.begin(),v.end());
}

bool check(string s){
    for(int i=0;i<N;i++){
        int first_idx = s.find(condition[i][0]); //N
        int second_idx = s.find(condition[i][1]); //F
        char cond = condition[i][2]; //=
        int num = condition[i][3]-'0'; // 2
        int dist = abs(first_idx - second_idx);
        if(cond == '>'){
            if(!(dist-1>num)) return false;
        }else if(cond == '<'){
            if(!(dist-1<num)) return false;
        }else{
            if(dist-1 != num) return false;
        }
    }
    return true;
}

void solve(){
    do{
        string s="";
        for(int i=0;i<v.size();i++){
            s+=v[i];
        } 
        if(check(s)) answer++;
    }while(next_permutation(v.begin(),v.end()));
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> d) {
    Data.clear();
    answer=0;
    v.clear();
    for (int i = 0; i < 101; i++) {
        condition[i].clear();
    }
    Data = d;
    N=n;
    init();
    solve();
    
    return answer;
}
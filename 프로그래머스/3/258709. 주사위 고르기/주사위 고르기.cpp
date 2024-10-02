#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int d_num=0;
vector<int> d_idx;
vector<int> temp;
vector<vector<int>> combi;
int maxWin =0;
void findDiceCombi(int depth, int sum, vector<int>&A_D, vector<int>&combi,vector<vector<int>>&dice){
    if(depth == combi.size()){
        A_D.push_back(sum);
        return;
    }
    for(int i=0;i<dice[combi[depth]-1].size();i++){
        sum+=dice[combi[depth]-1][i];
        findDiceCombi(depth+1,sum,A_D,combi,dice);
        sum-=dice[combi[depth]-1][i];
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    d_num = dice.size();
    for(int i=0;i<d_num;i++){
        d_idx.push_back(i+1);
    }
    for(int i=0;i<d_num/2;i++){
        temp.push_back(1);
    }
    for(int i=0;i<d_num/2;i++){
        temp.push_back(0);
    }
    
    do{
        vector<int>tmp;
        for(int i=0;i<d_num;i++){
            if(temp[i]==1) tmp.push_back(d_idx[i]);
        }
        combi.push_back(tmp);
    }while(prev_permutation(temp.begin(),temp.end()));
    
    int start = 0;
    int end = combi.size()-1;
    
    while(start<end){
        vector<int>A_D;
        vector<int>B_D;
        findDiceCombi(0,0,A_D,combi[start],dice);
        findDiceCombi(0,0,B_D,combi[end],dice);
        
        sort(A_D.begin(),A_D.end());
        sort(B_D.begin(),B_D.end());
        
        int win1 =0;
        int win2 =0;
        for(auto n : A_D){
            int win = lower_bound(B_D.begin(),B_D.end(),n) - B_D.begin();
            if(win>=0) win1+=win;
        }
        
        for(auto n : B_D){
            int win = lower_bound(A_D.begin(),A_D.end(),n) - A_D.begin();
            if(win>=0) win2+=win;
        }
        
        if(win1>win2&& win1>maxWin){
            answer = combi[start];
            maxWin = win1;
        }else if(win2 > win1 && win2 > maxWin){
            answer = combi[end];
            maxWin = win2;
        }
        
        start++;
        end--;
    }

    return answer;
}
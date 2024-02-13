#include <string>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

void dfs(int N, int target, vector<int>& container, vector<vector<int>>& combinations, int index){
    if(container.size() >= target){
        combinations.push_back(container);
        return; 
    }

    for(int i = index; i < N; i++){
        container.push_back(i+1); 
        dfs(N, target, container, combinations, i + 1); 
        container.pop_back(); 
    }
}

void findSum(vector<int>& v, vector<int>& tmp, int& currentSum, vector<vector<int>>& dice, int index){
    if(index >= v.size()){
        tmp.push_back(currentSum);
        return; 
    }

    for(int i = 0; i < dice[v[index]-1].size(); i++){
        currentSum += dice[v[index]-1][i];
        findSum(v,tmp,currentSum,dice,index+1); 
        currentSum -= dice[v[index]-1][i]; 
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer = {0,0}; 
    vector<vector<int>> combinations; 
    vector<int> container; 
    int N = dice.size();
    int target = dice.size() / 2; 
    dfs(N,target,container,combinations, 0); 
    int start = 0, end = combinations.size()-1; 
    int curr_maxRate = 0; 

    while(start < end){
        int currentSum1 = 0, currentSum2 = 0; 
        vector<int> tmp1, tmp2; 

        findSum(combinations[start],tmp1,currentSum1,dice,0); 
        findSum(combinations[end],tmp2,currentSum2,dice,0); 

        sort(tmp1.begin(),tmp1.end());
        sort(tmp2.begin(),tmp2.end()); 

        int winRate1 = 0, winRate2 = 0; 
        for(int n : tmp1){
            int win = lower_bound(tmp2.begin(), tmp2.end(), n) - tmp2.begin(); 
            if(win - 1 > 0) winRate1 += win; 
        }
        for(int n : tmp2){
            int win = lower_bound(tmp1.begin(), tmp1.end(), n) - tmp1.begin(); 
            if(win - 1 > 0) winRate2 += win; 
        }



        //여기서는 아마 서로 비교하는 계산 로직? 
        if(winRate1 > winRate2){
            if(winRate1 > curr_maxRate){
                curr_maxRate = winRate1; 
                answer = combinations[start];
            }
        } else if(winRate2 > winRate1){
            if(winRate2 > curr_maxRate){
                curr_maxRate = winRate2; 
                answer = combinations[end];
            }
        }

        tmp1.clear();
        tmp2.clear(); 
        start++;
        end--; 
    }
    return answer;
}
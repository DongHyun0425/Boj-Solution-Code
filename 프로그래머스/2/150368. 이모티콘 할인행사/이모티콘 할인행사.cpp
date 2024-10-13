#include <string>
#include <vector>
#include <iostream>

using namespace std;
int e_size=0;
vector<int> answer;
int d[4]={10,20,30,40};
vector<vector<int>> users;
vector<int> emoticons;
void cal(vector <int> &v){
    int plus = 0;
    int T_A =0;
    for(int i=0;i<users.size();i++){
        int rate = users[i][0];
        int amount = users[i][1];
        int tmp = 0;
        for(int j=0;j<v.size();j++){
            if(rate <=v[j]){
                tmp +=(emoticons[j]*(100-v[j]))/100;
            }
        }
        if(amount <= tmp){
            plus++;
        }else{
            T_A += tmp;
        }
    }
    if(plus>answer[0]){
        answer[0]=plus;
        answer[1]=T_A;
    }else if(plus == answer[0] && T_A > answer[1]){
        answer[1]=T_A;//?+=
    }
}

void discount_combi(vector<int>&v){
    if(v.size()==e_size){
        cal(v);
        return;
    }
    
    for(int i=0;i<4;i++){
        v.push_back(d[i]);
        discount_combi(v);
        v.pop_back();
    }
}


vector<int> solution(vector<vector<int>> userss, vector<int> emoticonss) {
    emoticons = emoticonss;
    users=userss;
    answer.push_back(0);
    answer.push_back(0);
    e_size=emoticons.size();
    vector<int>v;
    discount_combi(v);
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string,vector<string>> m;
map<string,int> van;

void init(vector<string> &id_list){
    for(int i=0;i<id_list.size();i++){
        vector<string>s;
        m[id_list[i]] = s;
        van[id_list[i]] = 0;
    }
}

void check(string user, string attack){
    auto mapit = m.find(user);
    vector<string> & tmp = mapit -> second;
    if(find(tmp.begin(),tmp.end(),attack)==tmp.end()){
        tmp.push_back(attack);
        map<string,int>::iterator iter;
        van[attack]++;
    }
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    if(id_list.size()>k){
    init(id_list);
    
    for(int i=0;i<report.size();i++){
        int j=0;
        string user = "";
        string attack = "";
        for(j=0;j<report[i].size();j++){
            if(report[i][j] != ' '){
                user+=report[i][j];
            }else{
                break;
            }
        }
        for(int x=j+1; x<report[i].size();x++){
            attack += report[i][x];
        }
        
        check(user,attack);   
    }
    
    for(int i=0;i<id_list.size();i++){
            string check = id_list[i];
            auto mapit = m.find(check);
            vector<string> & tmp = mapit -> second;
            int total=0;
            for(int i=0;i<tmp.size();i++){
                string t = tmp[i];
                if(van[t]>=k){
                    total++;
                }
            }
            answer.push_back(total);
    }
    }else{
        for(int i=0;i<id_list.size();i++){
            answer.push_back(0);
        }
    }
    return answer;
}
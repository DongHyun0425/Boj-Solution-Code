#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

vector<char>v;
vector<pair<string,int>>table;
vector<string> find_max[11];
int mymax[30]={0,};

void mycheck(){
    string combi="";
    for(int i=0;i<v.size();i++){
        combi+=v[i];
    }
    
    int flag=0;
    for(int i=0;i<table.size();i++){
        if(table[i].first==combi){
            table[i].second++;
            flag=1;
        }
    }
    if(flag==0){
        table.push_back({combi,1});
    }
}


void make_combi(string s, int cnt, int tmp){
    if(cnt==v.size()){
        mycheck();
        return;
    }
    
    for(int i = tmp; i<s.size(); i++){
        v.push_back(s[i]);
        make_combi(s,cnt,i+1);
        v.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0;i<orders.size();i++){
        string tmp = orders[i];
        sort(tmp.begin(),tmp.end());
        for(int j=0;j<course.size();j++){
            make_combi(tmp,course[j],0);
        }
    }
    
    for(int i=0;i<table.size();i++){
        //cout<<table[i].first<<" "<<table[i].second<<"\n";
        string s = table[i].first;
        int cnt = table[i].second;
        int s_size = s.size();
        if(cnt>=2){
          //크거나, 같은경우
          if(mymax[s_size]<cnt){
            find_max[s_size].clear();
            find_max[s_size].push_back(s);
            mymax[s_size]=cnt;
          }else if(mymax[s_size]<=cnt){
            find_max[s_size].push_back(s);    
          }
        }
    }
    /*
    for(int i=0;i<course.size();i++){
        cout<<"문자열 "<<course[i]<<"개"<<"\n";
        for(int j=0;j<find_max[course[i]].size();j++){
            cout<<find_max[course[i]][j]<<" ";
        }
        cout<<"\n";
    }
    */
    map<string,int>m;
    for(int i=0;i<course.size();i++){
        if(find_max[course[i]].size()>0){
            for(int j=0;j<find_max[course[i]].size();j++){
                m[find_max[course[i]][j]]=0;
            }
        }
    }
    
    for (auto iter : m) {
        answer.push_back(iter.first);
    }
    
    return answer;
}
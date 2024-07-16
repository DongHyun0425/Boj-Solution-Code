#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int,int>m;

bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.second>b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    
    string tmp="";
    for(int i=0;i<s.size();i++){
        if(s[i]!='{'){
            if(s[i]=='}'||s[i]==','){
                if(tmp.size()>0){
                    m[stoi(tmp)]++;
                    tmp="";
                }
            }else{
                tmp+=s[i];
            }
        }
    }
    
    vector<pair<int,int>>v(m.begin(),m.end());
    
    sort(v.begin(),v.end(),comp);
    
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].first);
    }
    
    return answer;
}
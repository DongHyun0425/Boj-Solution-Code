#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> answer;
map<string,string> m;
vector<string> complete_paser;

void paser(string temp){
    string t;
    for(int i=0;i<temp.size();i++){
        if(temp[i]!=' '){
            t+=temp[i];
        }else{
            complete_paser.push_back(t);
            t="";
        }
    }
    complete_paser.push_back(t);
}

void LogicEnter(){
    
    string uid = complete_paser[1];
    string neck = complete_paser[2];
    
    if(m.find(uid)!=m.end()){
        m[uid]=neck;
    }else{
        m.insert(make_pair(uid, neck));
    }
    
}

void LogicChange(){
    string uid = complete_paser[1];
    string neack = complete_paser[2];
    m[uid]=neack;
    
}

void makeEnter(){
     string uid = complete_paser[1];
    string neck = m[uid];
    string temp = neck+"님이 들어왔습니다.";
    answer.push_back(temp);
}

void makeLeave(){
     string uid = complete_paser[1];
    string neck = m[uid];
    string temp = neck+"님이 나갔습니다.";
    answer.push_back(temp);
}

vector<string> solution(vector<string> record) {
    for(int i=0;i<record.size();i++){
        paser(record[i]);
        
        
        if(complete_paser[0]=="Enter"){
            LogicEnter();
            
            complete_paser.clear();
        }
        else if(complete_paser[0]=="Change"){
            LogicChange();
            complete_paser.clear();
        }else{
              complete_paser.clear();
        }
    }
    
    
    for(int i=0;i<record.size();i++){
        paser(record[i]);
        if(complete_paser[0]=="Enter"){
            makeEnter();
            complete_paser.clear();
        }else if(complete_paser[0]=="Leave"){
            makeLeave();
            complete_paser.clear();
        }else{
          complete_paser.clear();
        }
    }
    
    return answer;
}
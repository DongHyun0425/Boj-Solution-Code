#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string,int> m;

bool mycheck(string today, string date, int addmonth){
    string ty="";
    string tm="";
    string td="";
    for(int i=0;i<4;i++){
        ty+=today[i];
    }    
    for(int i=5;i<7;i++){
        tm+=today[i];
    }    
    for(int i=8;i<10;i++){
        td+=today[i];
    }
    
    string y="";
    string m="";
    string d="";
    
    for(int i=0;i<4;i++){
        y+=date[i];
    }    
    for(int i=5;i<7;i++){
        m+=date[i];
    }    
    for(int i=8;i<10;i++){
        d+=date[i];
    }
    
    long long todaytotal= stoi(ty) * 12 * 28 + stoi(tm) * 28 + stoi(td);
    long long pritotal = stoi(y) * 12 * 28 + (stoi(m)+addmonth) * 28 + stoi(d);
    if(todaytotal>pritotal-1){
        return false;
    }
    return true;
        
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    //map만들기
    for(int i=0;i<terms.size();i++){
        string policy = "";
        policy += terms[i][0];
        int month = 0;
        string tmp ="";
        for(int j=2;j<terms[i].size();j++){
            tmp+=terms[i][j];
        }
        month = stoi(tmp);
        m.insert({policy, month});
    }
    
    for(int i=0;i<privacies.size();i++){
        string date = "";
        int j=0;
        for(j=0;j<privacies[i].size();j++){
            if(privacies[i][j] != ' '){
                date +=privacies[i][j];
            }else{
                break;
            }
        }
        string policy ="";
        policy+=privacies[i][j+1];
        
        //현재 	2021.05.02 A 파싱완료
        
        int month = m[policy];
        
        if(!mycheck(today,date,month)){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
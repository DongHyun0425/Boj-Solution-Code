#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<char,int>>v;

void init(){
    v.push_back({'R',0});
    v.push_back({'T',0});
    v.push_back({'C',0});
    v.push_back({'F',0});
    v.push_back({'J',0});
    v.push_back({'M',0});
    v.push_back({'A',0});
    v.push_back({'N',0});
}

string solution(vector<string> survey, vector<int> choices) {
    init();
    string answer = "";
    
    for(int i=0;i<survey.size();i++){
        char no = survey[i][0];
        char ok = survey[i][1];
        if(choices[i]==1){
            auto it = find_if(v.begin(),v.end(),[&no](const pair<char, int>& elem){ return elem.first == no; });
            it -> second+=3;
        } 
        if(choices[i]==2){
            auto it = find_if(v.begin(),v.end(),[&no](const pair<char, int>& elem){ return elem.first == no; });
            it -> second+=2;
        }
        if(choices[i]==3){
            auto it = find_if(v.begin(),v.end(),[&no](const pair<char, int>& elem){ return elem.first == no; });
            it -> second++;
        }
        if(choices[i]==5){
            auto it = find_if(v.begin(),v.end(),[&ok](const pair<char, int>& elem){ return elem.first == ok; });
            it -> second++;
        }
        if(choices[i]==6){
            auto it = find_if(v.begin(),v.end(),[&ok](const pair<char, int>& elem){ return elem.first == ok; });
            it -> second+=2;
        }
        if(choices[i]==7){
            auto it = find_if(v.begin(),v.end(),[&ok](const pair<char, int>& elem){ return elem.first == ok; });
            it -> second+=3;
        }
    }
    
    
    if(v[0].second>=v[1].second){
        answer+='R';
    }else{
        answer+='T';
    }
    
    if(v[2].second>=v[3].second){
        answer+='C';
    }else{
        answer+='F';
    }
    
    if(v[4].second>=v[5].second){
        answer+='J';
    }else{
        answer+='M';
    }
    
    if(v[6].second>=v[7].second){
        answer+='A';
    }else{
        answer+='N';
    }
    return answer;
}
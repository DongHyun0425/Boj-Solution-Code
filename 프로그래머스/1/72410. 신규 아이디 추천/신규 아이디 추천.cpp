#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

string solution(string new_id) {
    string answer ="";
    //1단계
    for(int i=0;i<new_id.size();i++){
        if('A'<=new_id[i] && new_id[i]<='Z'){
            new_id[i]+=32;
        }
    }
    
    //2단계
    queue <char> q;
    for(int i=0;i<new_id.size();i++){
        if('a'<=new_id[i] && new_id[i]<='z'){
            q.push(new_id[i]);
        }else if('0'<=new_id[i] && new_id[i]<='9'){
            q.push(new_id[i]);
        }else if (new_id[i] == '-'|| new_id[i] == '_' || new_id[i] == '.'){
            q.push(new_id[i]);
        }
    }
    
    //3단계
    int flag = 0;
    deque<char>t;
    while(!q.empty()){
        if(flag==0 && q.front()=='.'){
            flag = 1;
            t.push_back(q.front());
            q.pop();
        }else if(flag == 1 && q.front()=='.'){
            q.pop();
        }else{
            flag = 0; 
            t.push_back(q.front());
            q.pop();
        }
    }
    
    //4단계
    if(!t.empty() && t.front()=='.'){
        t.pop_front();
    }
    
    if(!t.empty() && t.back()=='.'){
        t.pop_back();
    }
    
    //5단계
    if(t.empty()){
        t.push_back('a');
    }
    
    deque<char>e;
    //6단계
    for(int i=0;i<t.size();i++){
        if(i>14){
            break;
        }
        e.push_back(t[i]);
    }
    
    if(e.back()=='.'){
        e.pop_back();
    }
   
    if(e.size()<=2){
        char tmp = e.back();
        while(e.size()!=3){
            e.push_back(tmp);
        }
    }
    
    for(int i=0;i<e.size();i++){
        answer+=e[i];
    }
    
    return answer;
}
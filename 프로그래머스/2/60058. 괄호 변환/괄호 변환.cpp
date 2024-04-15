#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool correct(string tmp){
    stack<char> s;
    s.push(tmp[0]);
    
    for(int i=1;i<tmp.size();i++){
        if(tmp[i]==')' && s.size()>0 && s.top()=='('){
            s.pop();
        }else{
            s.push(tmp[i]);
        }
    }
    
    if(s.size() == 0){
        return true;
    }else{
        return false;
    }
}

void divide(string & u, string & v, string &s){
    int count1=0;
    int count2=0;
    int i=0;
    for(i=0;i<s.size();i++){
        if('('==s[i]){
            count1++;
        }else{
            count2++;
        }
        
        u+=s[i];
        
        if(count1==count2){
            break;
        }
    }
    for(int j=i+1;j<s.size();j++){
        v+=s[j];
    }
}

string check(string s){
    if(s.size()==0){
        return "";
    }
    
    string u = "";
    string v = "";
    
    divide(u,v,s);
    
    if(correct(u)){
        string x = check(v);
        return u+x;
    }else{
        string tmp="";
        tmp+='(';
        string x = check(v);
        tmp +=x;
        tmp +=')';
        string newU = u.substr(1, u.length() - 2);
        for(int i=0;i<newU.size();i++){
            if(newU[i]=='('){
                newU[i]=')';
            }else{
                 newU[i]='(';
            }
        }
        tmp+=newU;
        return tmp;
    }
}

string solution(string p) {
    string answer = "";
    if(correct(p)){
        answer+=p;
        cout<<"correct";
    }else{
        cout<<"not correct";
        answer += check(p);
    }
    
    return answer;
}
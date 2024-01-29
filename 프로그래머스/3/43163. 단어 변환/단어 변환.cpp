#include <string>
#include <vector>
#include <iostream>

using namespace std;

int result =100000;
int visited[51]={0,};
vector <string> word;

int mycheck(string temp, string sample){
    int c=0;
    for(int i=0;i<temp.size();i++){
        if(temp[i]!=sample[i]){
            c++;
        }
    }
    return c;
}

void search(string temp,int count,string target){
    if(temp==target && result>count){
        result=count;
        cout<<"result change"<<result;
        return ;
    }
    
    for(int i=0;i<word.size();i++){
        if(mycheck(temp,word[i])==1 && visited[i]==0){
            visited[i]=1;
            cout<<word[i]<<" ";
            search(word[i],count+1,target);
            visited[i]=0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int ah=0;
    for(int i=0;i<words.size();i++){
        if(words[i]==target){
            ah++;
        }
        word.push_back(words[i]);
    }
    if(ah>0){
    search(begin,0,target);
    return result;
    }else{
        return 0;
    }
}
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int map1[51][51];
int map2[51][3];
map<string,int> table;
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    for(int i=0;i<friends.size();i++){
        table.insert({friends[i],i});
    }
    for(int i=0;i<gifts.size();i++){
        string give="";
        string get = "";
        vector<string>v;
        stringstream ss(gifts[i]);
        string tmp;
        while(ss>>tmp){
            v.push_back(tmp);
        }
        
        give=v[0];
        get=v[1];
        
        int give_idx=0;
        int get_idx=0;
        for(auto iter: table){
            if(iter.first==give) give_idx = iter.second;
            if(iter.first==get) get_idx = iter.second;
        }
        
        map1[give_idx][get_idx]++;
        map2[give_idx][0]++;
        map2[get_idx][1]++;
    }
    for(int i=0;i<friends.size();i++){
        map2[i][2] = map2[i][0]-map2[i][1];
    }
    
    for(int i=0;i<friends.size();i++){
        int tmp=0;
        for(int j=0;j<friends.size();j++){
            if(i==j) continue;
            if(map1[i][j]!=0 && map1[i][j]>map1[j][i]){
                tmp++;
            }else{
                //내가 안줬는데 상대는 나한테 준경우 어차피 상대 측에서 ++할거임
                if((map1[i][j]==map1[j][i]) && map2[i][2]>map2[j][2]){
                    tmp++;
                }
            }
        }
        if(answer<tmp) answer=tmp;
    }
    return answer;
}
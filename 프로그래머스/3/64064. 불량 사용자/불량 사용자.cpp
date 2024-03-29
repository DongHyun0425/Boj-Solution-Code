#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<int>v;
    for(int i=0;i<user_id.size();i++){
        v.push_back(i);
    }
    vector<string> t;
    int y=0;
    map<int, vector<int>> map;
    do{
        vector<int>yy;
        int k=0;
        bool check[9]={false,};
        for(int i=0;i<v.size();i++){
            for(int j=0;j<banned_id.size();j++){
                if(!check[j] && user_id[v[i]].size()==banned_id[j].size()){
                    int x=0;
                    for(int a=0;a<banned_id[j].size();a++){
                        if(banned_id[j][a]=='*'){
                            x++;
                        }else if(banned_id[j][a]==user_id[v[i]][a]){
                            x++;
                        }
                    }
                    if(x==user_id[v[i]].size()){
                        check[j]=true;
                        k++;
                        yy.push_back(v[i]);
                        yy.push_back(j);
                        break;
                    }
                }
            }
        }
        if(k==banned_id.size()){
            map[y]=yy;
            y++;
        }
    }while(next_permutation(v.begin(),v.end()));
    
    return map.size();
}
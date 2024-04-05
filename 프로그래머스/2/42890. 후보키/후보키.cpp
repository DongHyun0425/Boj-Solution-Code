#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int k = 0;
int c = 0;
vector<string>map[21];

void makeMap(vector<vector<string>> & relation){
    for(int i=0;i<k;i++){
        for(int j=0;j<relation.size();j++){
            string temp = relation[j][i];
            map[i].push_back(temp);
        }
    }
}


bool mycheck(vector<int> & t){
    set<string>s;
    vector<string>temp;
    for(int i=0;i<c;i++){
        for(int j=0;j<t.size();j++){
            string a = map[t[j]][i];
            temp.push_back(a);
        }
        //sort(temp.begin(),temp.end());
        string x="";
        for(int z=0;z<temp.size();z++){
            x+=temp[z];
        }
        temp.clear();
        int ssize = s.size();
        s.insert(x);
        int sssize = s.size();
        if(sssize==ssize){
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    k=relation[0].size();
    makeMap(relation);
    c=map[0].size();
    
    vector<int> v;
    vector<string> Only;
    for(int i=0;i<k;i++){
        v.push_back(i);
    }
    
    set <string> s;
    for(int i=1;i<=k;i++){
        int n = v.size();
        int r = i;
        do{
            vector<int>tmp;
            for(int j =0;j<r;j++){
                tmp.push_back(v[j]);
            }
            
            sort(tmp.begin(),tmp.end());
            string A="";
            for(int i=0;i<tmp.size();i++){
                A+=to_string(tmp[i]);
            }
            int ssize=s.size();
            s.insert(A);
            int sssize=s.size();
            
            if(ssize!=sssize){
              if(mycheck(tmp)){
                  int tcheck=0;
                  for(int i=0;i<Only.size();i++){
                      int Osize=Only[i].size();
                      int tsize=0;
                      for(int j=0;j<tmp.size();j++){
                          if(Only[i].find(tmp[j])!=string::npos){
                              tsize++;
                          }
                      }
                      if(tsize==Osize){
                          tcheck++;
                          break;
                      }
                  }
                  if(tcheck==0){
                      string xx="";
                      for(int k=0;k<tmp.size();k++){
                          xx+=tmp[k];
                      }
                      cout<<xx<<" ";
                      Only.push_back(xx);
                      
                  }
              }
            }
            reverse(v.begin()+r,v.end());
        }while(next_permutation(v.begin(),v.end()));
    }
    
    return Only.size();
}
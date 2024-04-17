#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int solution(vector<int> food_times, long long k) {
    vector<pair<long long,long long>> foods;
    for(int i=0;i<food_times.size();i++){
        foods.push_back({food_times[i],i+1});
    }
    sort(foods.begin(),foods.end());
    
    int height=0;
    int n = food_times.size();
    
    for(int i=0;i<foods.size();i++){
        long long needtime = (foods[i].first-height) * n;
        if(needtime == 0){
            n--;
            continue;
        }
        if(needtime <= k){
            k-=needtime;
            height = foods[i].first;
        }else{
            k%=n;
            sort(foods.begin()+i,foods.end(),comp);
            return foods[i+k].second;
        }
        n--;
    }
    return -1;
}
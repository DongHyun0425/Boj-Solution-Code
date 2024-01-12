#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <int>v;
long long solution(int n, vector<int> times) {
    long long answer = 10000000;
    long long start = 1;
    sort(times.begin(),times.end());
    long long end = (long long) times[times.size()-1]*n;
    while(start<=end){
        long long mid = (start+end)/2;
        long long int cnt =0;
        for(int i=0;i<times.size();i++){
            cnt+=(mid/(long long) times[i]);
        }
        if(cnt<n){
            start=mid+1;
        }else{
            
            answer = mid;
            
            end = mid-1;
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(),routes.end());
    int answer = 1;
    int camera = routes[0][1];
    for(int i=1;i<routes.size();i++){
        if(routes[i][0]>camera){
            camera=routes[i][1];
            answer++;
         }else if(routes[i][1]<camera){
            camera=routes[i][1];
        }
    }
    return answer;
}
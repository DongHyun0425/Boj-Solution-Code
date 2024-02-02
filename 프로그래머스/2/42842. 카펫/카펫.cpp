#include <string>
#include <vector>
#include <iostream>
using namespace std;
int g=0;
int s=0;
vector<int> answer;
void mycheck(int sero,int yellow,int brown){
    int bn=0;
    int garo = yellow/sero;
    int temp = garo+2;
    bn+=temp*2;
    bn+=sero*2;
    if(bn==brown){
        answer.push_back(temp);
        answer.push_back(sero+2);
        //cout<<answer[0]<<" "<<answer[1];
    }
}



vector<int> solution(int brown, int yellow) {
    int i=1;
    while(1){
        if(yellow/i<i){
            break;
        }
        if(yellow%i==0){
            mycheck(i,yellow,brown);
        }
        i++;
    }
    
    return answer;
}
#include <string>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;


int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int GCD_A = arrayA[0];
    
    for(int i=0;i<arrayA.size()-1;i++){    
        GCD_A = gcd(GCD_A,arrayA[i+1]);
    }
    
    int GCD_B = arrayB[0];
    
    for(int i=0;i<arrayB.size()-1;i++){    
         GCD_B = gcd(GCD_B,arrayB[i+1]);
        
    }
    
    bool A_flag = false;
    //A의 최대공약수로 나누어지는경우
    for(int i=0;i<arrayB.size();i++){
        if(arrayB[i]%GCD_A == 0) {
            A_flag = true;
            break;
        }
    }
    int semi_A_answer = 0;
    if(!A_flag)semi_A_answer = GCD_A;
    
    bool B_flag = false;
    //B의 최대공약수로 나누어지는경우
    for(int i=0;i<arrayA.size();i++){
        if(arrayA[i]%GCD_B == 0) {
            B_flag = true;
            break;
        }
    }
    int semi_B_answer = 0;
    if(!B_flag)semi_B_answer = GCD_B;
    
    if(semi_A_answer>semi_B_answer) return semi_A_answer;
    else return semi_B_answer;
}
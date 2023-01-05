#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i = 0; i < t.size()-p.size()+1; i++){
        for(int j = 0; j < p.size(); j++){
            int x = t[j+i] - '0';
            int y = p[j] - '0';
    
            if(x < y) {
                answer++;
                break;
            }
            else if(x==y){
                if(j==p.size()-1) answer++;
                continue;
            }
            break;
        }
    }
    return answer;
}
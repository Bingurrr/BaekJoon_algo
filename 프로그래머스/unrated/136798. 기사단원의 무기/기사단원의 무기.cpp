#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;



int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; i++) {
        int k = 0;
        for(int j = 1; j <= sqrt(i); j++){
            // cout << j << endl;
            if(i%j == 0){
                if(j==sqrt(i)) {
                    k++;
                }
                else {
                    k+=2;
                }
            }
            if(k > limit) break;
        }
        // cout << k << endl;
        if (k > limit) answer += power;
        else answer += k;
    }
    return answer;
}
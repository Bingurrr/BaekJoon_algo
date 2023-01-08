#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    int k = n-1;
    answer = n-1;
    for(int i = 2; i <= sqrt(k); i++){
        if(k%i == 0){
            answer = i;
            break;
        }
    }
    return answer;
}
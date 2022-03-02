#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool is_(int num){
    int a = sqrt(num);
    if(a*a==num) return true;
    return false;
}


int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i ++){
        if(is_(i)) answer -= i;
        else answer += i;
    }
    return answer;
}

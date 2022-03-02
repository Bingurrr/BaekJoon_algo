#include <string>
#include <vector>
#include <cmath>

using namespace std;
bool is_squared(long long n) {
    long long sqr = sqrt(n);
    if(sqr*sqr==n){
        return true;
    }
    return false;
}

long long solution(long long n) {
    long long answer = 0;
    if(is_squared(n)){
        return (sqrt(n)+1)*(sqrt(n)+1);
    }
    
    return -1;
}

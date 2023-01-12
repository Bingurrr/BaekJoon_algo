#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long int dist;

long long solution(int k, int d) {
    dist = d;
    long long answer = 0;
    long long int a = d;
    for(long long int i = 0; i <= d; i+=k){
        while(i*i + a*a > dist*dist) {
            a--;
        }
        answer += a/k+1;
    }
    return answer;
}
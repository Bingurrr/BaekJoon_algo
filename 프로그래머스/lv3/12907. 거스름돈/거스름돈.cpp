#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long dp[100001] = {0,};

int solution(int n, vector<int> money) {
    int answer = 0;
    dp[0] = 1;
    for(auto i : money){
        int k = 0;
        for(int j = i; j <= n; j++){
            k = 
            dp[j] += dp[j-i];
        }
    }
    answer = dp[n]%1000000007;
    return answer;
}
#include <string>
#include <vector>
#define mod 1000000007
using namespace std;

long long int dp[5001];

int solution(int n) {
    int answer = 0;
    //dp[2] = 3;
    //dp[4] = 11;
    //dp[k] = dp[k-2]*3 + dp[k-4] * 2;
    dp[2] = 3;
    dp[4] = 11;
    long long int k = 4;
    for(int i = 6; i <= n; i+=2){
        dp[i] = (dp[i-2]*k%mod - dp[i-4]%mod + mod)%mod;
    }
    
    return dp[n];
}
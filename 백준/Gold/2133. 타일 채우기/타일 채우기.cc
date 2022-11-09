#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 10001

using namespace std;

int n;
int dp[31];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    cin >> n;
    for(int i = 4; i <=n; i++){
        if(i%2==1) continue;
        dp[i] = dp[i-2]*3+2;
        for(int j = i-4; j >=0; j-=2){
            dp[i] += 2*dp[j];
        }
    }
    cout << dp[n];
}
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[5002];
int main(){
    cin >> n;
    dp[3] = 1;
    dp[5] = 1;
    for(int i = 6; i <=n; i++){
        if(dp[i-3]==0 && dp[i-5] != 0){
            dp[i] = dp[i-5] + 1;
            continue;
        }
        else if(dp[i-3] != 0 && dp[i-5]==0){
            dp[i] = dp[i-3] + 1;
            continue;
        }
        else if(dp[i-3]==0&&dp[i-5]==0){
            continue;
        }
        dp[i] = min(dp[i-3]+1,dp[i-5]+1);
        //cout << i << " " << dp[i] << '\n';
    }
    if(dp[n] == 0) dp[n] = -1;
    cout << dp[n];
    
}
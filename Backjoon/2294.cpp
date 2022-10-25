#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans;
int money [100];
int dp[100001];
int main(){
    cin >> n >> k;
    for(int i = 0; i <= k; i++){
        dp[i] = 99999999;
    }
    for(int i = 0; i < n; i++){
        cin >> money[i];
        dp[money[i]] = 1;
    }
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = money[i]; j <= k; j++){
            dp[j] = min(dp[j], dp[j-money[i]] +1);
        }
    }
    if(dp[k] == 99999999) dp[k] = -1;
    cout << dp[k];
}

#include<iostream>
#include<algorithm>

using namespace std;


int n;
int arr[1001][3];
int dp[1001][3];
int ans = 1000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for(int i  = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j==i) dp[1][j] = arr[1][j];
            else dp[1][j] = 1000000;
        }
        for(int j = 2; j <= n; j++){
            dp[j][0] = arr[j][0] + min(dp[j-1][1], dp[j-1][2]);
            dp[j][1] = arr[j][1] + min(dp[j-1][0], dp[j-1][2]);
            dp[j][2] = arr[j][2] + min(dp[j-1][1], dp[j-1][0]);
        }
        for(int j = 0; j < 3; j++){
            if(i==j) continue;
            else ans = min(ans,dp[n][j]); 
        }
    }
    cout << ans;
}
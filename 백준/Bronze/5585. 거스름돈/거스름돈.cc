#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
int dp[1001];
int m[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> n;
    m[0] = 1;
    m[1] = 5;
    m[2] = 10;
    m[3] = 50;
    m[4] = 100;
    m[5] = 500;

    for(int i = 0; i < 1001; i++){
        dp[i] = 10000;
    }
    dp[1] = 1;
    dp[5] = 1;
    dp[10] = 1;
    dp[50] = 1;
    dp[100] = 1;
    dp[500] = 1;
    
    int money = 1000 - n;
    for(int i = 0; i < 6; i++){
        for(int j = m[i]; j <= money; j++){
            dp[j] = min(dp[j], dp[j-m[i]]+1);
        }
    }
    cout << dp[money];
}
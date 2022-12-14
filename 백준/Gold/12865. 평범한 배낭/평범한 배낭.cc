#include <iostream>

using namespace std;

int n, k;
int weight[101];
int value[101];
int dp[101][100001];


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = weight[i]; j <= k; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
        }
        for(int j = 1; j < weight[i]; j++){
            dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k];
	return 0;
}
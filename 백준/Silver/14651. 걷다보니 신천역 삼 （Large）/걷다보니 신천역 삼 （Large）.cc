#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000009

int N;
int dp[3][33334];


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> N;

	dp[0][1] = 0; 
	dp[1][1] = 0;
	dp[2][1] = 0; 

	dp[0][2] = 2; 
	dp[1][2] = 2;
	dp[2][2] = 2; 

	for (int i = 3; i <= N; i++){

		dp[0][i] += (dp[0][i - 1] + dp[1][i - 1]) % MOD + dp[2][i - 1];
		dp[1][i] += (dp[0][i - 1] + dp[1][i - 1]) % MOD + dp[2][i - 1];
		dp[2][i] += (dp[0][i - 1] + dp[1][i - 1]) % MOD + dp[2][i - 1];

		for (int j = 0; j < 3; j++){
			dp[j][i] %= MOD;
		}
	}

	cout << dp[0][N] << '\n';

}
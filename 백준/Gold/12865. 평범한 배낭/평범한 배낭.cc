#include <iostream>
#include <algorithm>
#define MAX_SIZE 101
#define MAX_INPUT 100001

using namespace std;

int value[MAX_SIZE];
int weight[MAX_SIZE];
// int dp[MAX_INPUT];
int dp[MAX_SIZE][MAX_INPUT];
int n, k;

// 1차 풀이
// 중복 제거를 못했음 ->dp +  knapsack 알고리즘 적용해야함

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = weight[i]; j <= k; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i]);
			//dp[j] = max(dp[j], dp[j-weight[i] + value[i]]);
		}
		for (int j = 1; j < weight[i]; j++) {
			dp[i][j] = dp[i - 1][j];
		}
	}
	//for (int i = 0; i <= k; i++) cout << dp[i] << " ";
	cout << dp[n][k];
}

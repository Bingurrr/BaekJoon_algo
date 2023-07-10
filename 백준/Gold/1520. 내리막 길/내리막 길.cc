#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#include <stack>
#include <regex>

using namespace std;

int height[501][501]; 
int dp[501][501]; 
int m, n, ans; 
int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1}; 


int dfs(int x, int y){ 
	if(x == m - 1 && y == n - 1) return 1; 
	if(dp[x][y] != -1) return dp[x][y]; 

	dp[x][y] = 0;
	for(int i = 0; i < 4; i++){ 
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 
		if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue; 
		if(height[x][y] > height[nx][ny]){
			dp[x][y] += dfs(nx, ny); 
		}
	}
	return dp[x][y]; 
}


int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	cin >> m >> n; 
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> height[i][j];
            dp[i][j] = -1;
		}
	}
	ans = dfs(0, 0);
	cout << ans; 
	return 0;
}
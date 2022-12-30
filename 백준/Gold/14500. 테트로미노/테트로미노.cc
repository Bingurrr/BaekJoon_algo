#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

int arr[500][500];
bool c[500][500];
int n, m;
int ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void go(int x, int y, int sum, int cnt) {
    
	if (cnt == 4) {
		if (sum > ans) ans = sum;
		return;
	}
	if (x < 0 || x >= n || y < 0 || y >= m) return;

	if (c[x][y]) return;
	c[x][y] = true;

	for (int k = 0; k < 4; k++) {
		go(x + dx[k], y + dy[k], sum + arr[x][y], cnt+1);
	}

	c[x][y] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);	
	cin >> n >> m;
    
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			go(i, j, 0, 0);
			int tmp = 0;
			if (i + 2 < n && j + 1 < m) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
				if (tmp > ans) ans = tmp;
			}
			if (i + 2 < n && j - 1 >= 0) {
				tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j - 1];
				if (tmp > ans) ans = tmp;
			}
			if (i - 1 >= 0 && j + 2 < m) {
				tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1];
				if (tmp > ans) ans = tmp;
			}
			if (i + 1 < n && j + 2 < m) {
				tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
				if (tmp > ans) ans = tmp;
			}

		}
	}
	cout << ans << '\n';
	return 0;
}
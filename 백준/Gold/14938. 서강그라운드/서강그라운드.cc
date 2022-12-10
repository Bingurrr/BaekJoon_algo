#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;


int n, m, r;
int item[101];
int arr[101][101];
int town[101];
int ans;
int min_item = 0;
bool visited[101];

long long int sum;

int pick_min() {
	int min_value = INF;
	int idx = 0;
	for (int j = 1; j <= n; j++) {
		if (town[j] < min_value && !visited[j]) {
			min_value = town[j];
			idx = j;
		}
	}
	return idx;
}
void solve(int start) {
	for (int i = 1; i <= n; i++) {
		town[i] = arr[start][i];
	}
	visited[start] = true;
	town[start] = 0;
	for (int i = 1; i < n - 1; i++) {
		int current = pick_min();
		visited[current] = true;
		for (int j = 0; j <= n; j++) {
			if (!visited[j]) {
				if (town[current] + arr[current][j] < town[j]) {
					town[j] = town[current] + arr[current][j];
				}
			}
		}
	}
}



int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			town[j] = INF;
			visited[j] = false;
		}
		int k = 0;
		solve(i);
		for (int j = 1; j <= n; j++) {
			if (town[j] <= m) {
				k += item[j];
			}
		}
		if (ans < k) {
			ans = k;
		}
	}

	cout << ans;
	return 0;
}
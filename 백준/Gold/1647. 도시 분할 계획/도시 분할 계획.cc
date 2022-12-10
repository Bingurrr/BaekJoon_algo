// #include <iostream>
// #include <algorithm>

// using namespace std;

// struct town {
// 	int start;
// 	int end;
// 	int cost;
// };

// bool cmp(town x, town y) {
// 	if (x.cost >= y.cost) return false;
// 	else return true;
// }

// town arr[1000001];
// int pr[100001];
// int n, m;
// int ans;
// int cnt;

// int find(int i) {
// 	while (i != pr[i]) {
// 		i = pr[i];
// 	}
// 	return i;
// }
// void uni(int p, int q, int r) {
// 	int i = find(p);
// 	int j = find(q);
// 	if (i != j) {
// 		pr[i] = j;
// 		ans += r;
// 		cnt++;
// 	}
// }

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);
//     cout.tie(0);
// 	cin >> n >> m;
// 	for (int i = 0; i < m; i++) {
// 		cin >> arr[i].start >> arr[i].end >> arr[i].cost;
// 	}
// 	// init
// 	sort(arr, arr + m, cmp);
// 	for (int i = 0; i < m; i++) {
// 		uni(arr[i].start, arr[i].end, arr[i].cost);
// 		if (cnt == n - 2) break;
// 	}
// 	cout << ans;
// 	return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
int parent[100001];
int result;
int getParent(int num) {
	if (num == parent[num]) return num;
	return parent[num] = getParent(parent[num]);

}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b) {
		parent[a]= b;
	}
}
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<pair<int, pair<int, int>>> edge(m);
	for (int i = 0; i < m; i++) {
		int cost, a, b;
		cin >> a >> b >> cost;
		edge[i] = { cost,{a,b} };
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	sort(edge.begin(), edge.end());

	int maxCost = 0;
	for (int i = 0; i < m; i++) {
		int cost = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (!findParent(a, b)) {
			maxCost = max(maxCost, cost);
			result += cost;
			unionParent(a, b);
		}
	}
	cout << result-maxCost;

	return 0;
}
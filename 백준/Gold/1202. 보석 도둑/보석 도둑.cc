#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int main() {
	priority_queue<pair<int,int>> pq;

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> nv;
	vector <long> kv;
	int a, b;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		nv.push_back(pair<int, int>(a, b));
	}
	sort(nv.begin(), nv.end());
	
	for (int i = 0; i < k; i++) {
		cin >> a;
		kv.push_back(a);
	}
	sort(kv.begin(), kv.end());

	int bag;
	int ni = 0;
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		bag = kv[i];
		while (ni < n && bag >= nv[ni].first) {
			pq.push(pair<int, int>(nv[ni].second , nv[ni].first));
			ni++;
		}
		if (!pq.empty()) {
			pair<int, int> tmp = pq.top();
			pq.pop();
			sum += tmp.first;
		}
	}
	cout << sum << '\n';
}
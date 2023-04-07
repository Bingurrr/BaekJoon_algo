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
#define INF 2000000001

using namespace std;

string str;
vector<pair<int, int>> v;
stack<int> st;
set<string> s;
bool visited[201];

void solve(int n, int x) {
	if (n >= v.size()) {
		if (x > 0) {
			string tmp = "";
			for (int i = 0;i < str.length();i++) {
				if (visited[i]) tmp += str[i];
			}
			s.insert(tmp);
		}
		return;
	}
	else {
		solve(n + 1, x);
		visited[v[n].first] = false;
		visited[v[n].second] = false;

		solve(n + 1, x + 1);
		visited[v[n].first] = true;
		visited[v[n].second] = true;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> str;
	for (int i = 0; i < str.length();i++) {
		visited[i] = true;

		if (str[i] == '(') st.push(i);
		else if (str[i] == ')') {
			v.push_back({st.top(), i});
			st.pop();
		}
	}
	solve(0, 0);

	for (auto x : s) {
		cout << x << "\n";
	}
   
	return 0;
}

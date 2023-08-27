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
#define INF (1 << 30)

using namespace std;

int cnt[26] = { 0 , };
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> s;

	for (char i = 'a'; i <= 'z'; i++) {
		cout << (int)s.find(i) << ' ';
	}


	return 0;
}
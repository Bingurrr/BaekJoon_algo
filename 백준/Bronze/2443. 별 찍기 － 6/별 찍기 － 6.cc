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
#define endl "\n"
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = 1; j <= (2 * (N - i)) - 1; j++)
			cout << '*';
		cout << '\n';
	}
    
}

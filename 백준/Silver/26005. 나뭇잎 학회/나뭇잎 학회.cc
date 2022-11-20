#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 1001

using namespace std;

int n, idx;
long long int ans;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    ans = (n*n+1)/2;
    if(n==1) ans = 0;
    cout << ans;
	return 0;
}
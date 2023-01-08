#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#define INF 1000002
#define mod 1000000007
using namespace std;

int n;
long long int dp[INF];
long long int k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    dp[1] = 2;
    dp[2] = 7;
    dp[3] = 22;
    k = 1;
    for(int i = 4; i <= n; i++){
        k = (dp[i-3] +k);
        dp[i] = (k*2 + dp[i-2]*3 + dp[i-1]*2) %mod;
    }
    cout << dp[n];
	return 0; 
}

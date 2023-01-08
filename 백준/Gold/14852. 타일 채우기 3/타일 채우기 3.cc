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
    long long int a = 2;
    long long int b = 3;
    long long int c = 2;
    for(int i = 4; i <= n; i++){
        k = (dp[i-3] +k);
        dp[i] = (k*a + dp[i-2]*b + dp[i-1]*c) %mod;
    }
    cout << dp[n];
	return 0; 
}

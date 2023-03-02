#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 987654321

using namespace std;

int testcase, ans;
int n;
int dp[2][100001];


void solve(){
    dp[0][0] = 0;
    dp[1][0] = 0;
    
    for(int i = 2; i <= n; i++){
        dp[0][i] = max(dp[1][i-1],dp[1][i-2])+dp[0][i];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2])+ dp[1][i];
    }
    cout << max(dp[0][n], dp[1][n]) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> testcase;
    
    while(testcase > 0){
        testcase--;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> dp[0][i];
        }
        for(int i = 1; i <= n; i++){
            cin >> dp[1][i];
        }
        solve();
    }

    
	return 0;
}

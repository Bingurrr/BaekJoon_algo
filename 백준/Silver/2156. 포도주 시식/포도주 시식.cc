#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int arr[10001];
int dp[100001];
int n;
    

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    for(int i = 3; i <=n; i++){
        dp[i] = max(dp[i-1], max(dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i]));
    }
    cout << dp[n];
    return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 10001

using namespace std;

int t, n, m;
int money[21] = {0,};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i = 0; i <t; i++){
        cin >> n;
        int dp[10010] = {0,};
        dp[0] = 1;
        for(int j = 1; j <= n; j++){
            cin >> money[j];
        }
        cin >> m;
        
        for(int a = 1; a <= n; a++){
            for(int b = money[a]; b <= m; b++){
                dp[b] = dp[b] + dp[b-money[a]];
            }
        }
        cout << dp[m] << '\n';
        
    }

}
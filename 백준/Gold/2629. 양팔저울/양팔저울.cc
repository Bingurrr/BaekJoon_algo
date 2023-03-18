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

using namespace std;

int weight[31], dp[31][15001];
int n, k, x;

void solve(int i, int w){
    if(n < i || dp[i][w])
        return ;
        
    dp[i][w] = 1;
    solve(i + 1, w); 
    solve(i + 1, w + weight[i]); 
    solve(i + 1, abs(w - weight[i]));
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n; 
    for(int i = 0; i < n; i++)
        cin >> weight[i];
    solve(0, 0);
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> x;
        if(x > 15000) 
            cout << "N ";
        else if(dp[n][x])
            cout << "Y ";
        else
            cout << "N ";
    }
	return 0; 
}

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[21];
int visited[21];
int ans;
int sum;
void solve(int x, int k){
    if(sum == m && x!=0) ans++;

    for(int i = 0; i < n; i++){
        if(visited[i]==1 || k > i) continue;
        visited[i] = 1;
        sum += arr[i];
        solve(x+1,i);
        visited[i] = 0;
        sum -= arr[i];
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    solve(0,0);
    cout << ans;
	
	return 0;
}
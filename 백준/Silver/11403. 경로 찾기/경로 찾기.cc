#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
using namespace std;

int n;
int arr[101][101];
int ans[101][101];

void solve(int i){
    queue<int> q;
    // ans[i][i] = 1;
    for(int j = 0; j < n; j++){
        if(arr[i][j] == 1){
            ans[i][j] = 1;
            q.push(j);
        }
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int j = 0; j < n; j++){
            if(ans[i][j] == 0 && arr[t][j] ==1){
                ans[i][j] = 1;
                q.push(j);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        solve(i);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
using namespace std;

int n, m, k;
int a, b;
int ans, idx;
int arr[101][101];

int dfs(int x){
    queue<int> q;
    int bacon[101] = {0,};
    int s = 0;
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        if(arr[x][i] == 1) {
            q.push(i);
            bacon[i]++;
        }
    }
    cnt++;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(arr[f][i] == 1 && bacon[i] ==0){
                q.push(i);
                bacon[i] = bacon[f]+1;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i==x) continue;
        s+=bacon[i];
        // cout << bacon[i] << " ";
    }
    // cout << endl;
    return s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    ans = 2000000000;
    for(int i = 1; i <= n; i++){
        k = dfs(i);
        // cout << k << endl;
        if(ans > k){
            ans = k;
            idx = i;
        }
    }
    cout<< idx;
    return 0;
}

// 6 8 5 5 8
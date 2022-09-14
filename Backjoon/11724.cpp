#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
using namespace std;

bool map[1001][1001];
bool visited[1001];
int n, m;

void dfs(int num){
    visited[num] = true;
    for(int i = 1; i <= n; i++){
        if(map[num][i] && !visited[i]){
            dfs(i);
        }
    }
}

int main (){
    cin >> n >> m;
    int a, b;
    int ans = 0;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        map[a][b] = true;
        map[b][a] = true;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ans++;
            dfs(i);
        }
    }
    cout << ans;
    
    return 0;
    
}

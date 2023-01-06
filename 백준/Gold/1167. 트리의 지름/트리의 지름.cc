#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

int n;
int num, target, dist;
int far_vertex;
int ans;
bool visited[100001];
vector<pair<int, int>> v[100001];

void solve(int k, int cost){
    if(visited[k] == 1) return;
    visited[k] = 1;
    if(cost > ans){
        ans = cost;
        far_vertex = k;
    }
    for(auto i : v[k]){
        int x = i.first;
        int y = i.second;
        solve(x, y+cost);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;  
    for(int i = 0; i < n; i++){
        cin >> num;
        while(true){
            cin >> target;
            if(target==-1) break;
            cin >> dist;
            v[num].push_back({target, dist});
            v[target].push_back({num, dist});
        }
    }
    solve(1, 0);
    memset(visited, 0, sizeof(visited));
    solve(far_vertex, 0);
    cout << ans;
	return 0; 
}

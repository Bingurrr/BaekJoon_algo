#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>


using namespace std;

int n, k, ans;
bool visited[100010];
int arr[100010];
queue<pair<int,int>> q;
vector<int> path;


void solve(){
    q.push({n,0});
    visited[n] = true;
    arr[n] = -1;
    while(!q.empty()){
        int now_pos = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(now_pos == k){
            ans = cost;
            break;
        }
        int x_1 = now_pos - 1;
        int x_2 = now_pos + 1;
        int x_3 = now_pos * 2;
        
        //x-1;
        if(x_1 >= 0 && !visited[x_1]){
            q.push({x_1,cost+1});
            visited[x_1] = true;
            arr[x_1] = now_pos;
        }
        //x+1;
        if(x_2 <= k && !visited[x_2]){
            q.push({x_2,cost+1});
            visited[x_2] = true;
            arr[x_2] = now_pos;
        }
        //x*2
        if(x_3 <= k+1 && !visited[x_3]){
            q.push({x_3,cost+1});
            visited[x_3] = true;
            arr[x_3] = now_pos;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;

    solve();
    cout << ans << '\n';
    path.push_back(k);
    int idx = k;
    while (arr[idx] != -1) {
        path.emplace_back(arr[idx]);
        idx = arr[idx];
    }
    for (int i = path.size() - 1; i >= 0; i--){
		cout << path[i] << ' ';
    }
	return 0; 
}

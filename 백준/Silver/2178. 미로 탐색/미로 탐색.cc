#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int x, y, cnt;
char arr[102][102];
int visited[102][102];
queue<pair<int, int>> q;
queue<int> c;

void solve(){
    q.push({0,0});
    c.push(0);
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        cnt = c.front();
        if(x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == '0' ||visited[x][y] == 1){
            q.pop();
            c.pop();
            continue;
        }
        visited[x][y] = 1;
        if(x==n-1 && y==m-1){
            cout << cnt+1;
            break;
        }
        q.push({x+1,y});
        q.push({x-1,y});
        q.push({x,y+1});
        q.push({x,y-1});
        for(int i = 0; i < 4; i++)
            c.push(cnt+1);
        q.pop();
        c.pop();
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    solve();
	return 0; 
}
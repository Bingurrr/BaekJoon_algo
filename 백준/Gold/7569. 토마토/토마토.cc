#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

struct tomato{
    int x,y,z, day;
    tomato(int x, int y, int z, int day) : x(x), y(y), z(z), day(day) {}
};

int n, m, h;
int ans;
int cnt;
int arr[101][101][101];
queue<tomato> q;

void solve(){
    while(!q.empty()){
        tomato t = q.front();
        if(t.x < 0 || t.x >= m || t.y < 0 || t.y >= n || t.z <0 || t.z >= h || arr[t.z][t.y][t.x] == 2 || arr[t.z][t.y][t.x] == -1){
            q.pop();
            continue;
        }
        arr[t.z][t.y][t.x] = 2;
        cnt--;
        if(ans < t.day) ans = t.day;
        if(cnt==0) break;
        q.pop();
        q.push(tomato(t.x+1,t.y+0,t.z+0,t.day+1));
        q.push(tomato(t.x-1,t.y+0,t.z+0,t.day+1));
        q.push(tomato(t.x+0,t.y+1,t.z+0,t.day+1));
        q.push(tomato(t.x+0,t.y-1,t.z+0,t.day+1));
        q.push(tomato(t.x+0,t.y+0,t.z+1,t.day+1));
        q.push(tomato(t.x+0,t.y+0,t.z-1,t.day+1));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                    q.push(tomato(k+0,j+0,i+0,0));
                    cnt++;
                }
                else if(arr[i][j][k] == 0)
                    cnt++;
            }
        }
    }
    solve();
    if(cnt != 0) ans = -1;
    cout << ans;
	return 0; 
}
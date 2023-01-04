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
int x, y, ans;
char arr[26][26];
int visited[26][26];
int cnt[400];
queue<pair<int, int>> q;

void solve(int a, int b){
    q.push({a,b});
    int c = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        if(x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == '0' ||visited[x][y] == 1){
            q.pop();
            c--;
            continue;
        }
        visited[x][y] = 1;
        c+=4;
        q.push({x+1,y});
        q.push({x-1,y});
        q.push({x,y+1});
        q.push({x,y-1});
        q.pop();
    }
    cnt[ans] = c;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == '1' && visited[i][j] == 0){
                solve(i, j);
                ans++;
            }
        }
    }
    cout << ans << '\n';
    sort(cnt, cnt+ans);
    for(int i = 0; i < ans; i++){
        cout << cnt[i] << '\n';
    }
	return 0; 
}
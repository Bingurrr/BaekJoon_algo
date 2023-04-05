#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 2000000001

using namespace std;

int n, m, d, s;
int arr[51][51];
queue<pair<int ,int>> q;
queue<pair<int, int>> cloud;
int direction[9][2] = {{0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
bool is_cloud[52][52];
long long int ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cloud.push({n,1});
    cloud.push({n,2});
    cloud.push({n-1,1});
    cloud.push({n-1,2});
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < m; i++){
        cin >> d >> s;
        q.push({d,s});
    }

    while(!q.empty()){
        int r_move = (direction[q.front().first][0] * q.front().second)%n;
        int c_move = (direction[q.front().first][1] * q.front().second)%n;
        q.pop();
        queue<pair<int,int>> new_cloud;
        while(!cloud.empty()){
            int r = cloud.front().first;
            int c = cloud.front().second;
            cloud.pop();
            r+=r_move;
            c+=c_move;
            if(r > n){
                r -= n;
            }
            else if(r < 1){
                r += n;
            }
            if(c > n){
                c -= n;
            }
            else if(c < 1){
                c += n;
            }
            arr[r][c]++;
            new_cloud.push({r,c});
        }

        // 4단계
        while(!new_cloud.empty()){
            int water = 0;
            int r = new_cloud.front().first;
            int c = new_cloud.front().second; 
            is_cloud[r][c] = true;
            new_cloud.pop();

            if(r-1>=1 && c-1 >=1){
                if(arr[r-1][c-1] > 0){
                    water++;
                }
            }
            if(r-1>=1 && c+1 <=n){
                if(arr[r-1][c+1] > 0){
                    water++;
                }
            }
            if(r+1<=n && c-1 >=1){
                if(arr[r+1][c-1] > 0){
                    water++;
                }
            }
            if(r+1 <= n && c+1 <= n){
                if(arr[r+1][c+1] > 0){
                    water++;
                }
            }
            arr[r][c] += water;
        }
        // 5단계
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][j] >= 2 && is_cloud[i][j] == false){
                    arr[i][j] -= 2;
                    cloud.push({i,j});
                }
                is_cloud[i][j] = false;
            }
        }
    }
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans += arr[i][j];
        }
    }

    cout << ans;
    
	return 0;
}

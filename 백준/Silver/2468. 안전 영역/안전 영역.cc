#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
int n;
int arr[101][101];
int visited[101][101];
int ans = 1;
int height;
bool safe = false;

void sol(int x, int y){
    if(x <0 || y < 0 || x >=n || y >=n) return;
    if(x-1 >=0){
        if(arr[y][x-1] > height && visited[y][x-1] != height){
            visited[y][x-1] = height;
            sol(x-1, y);
        }
    }
    if(y-1 >= 0){
        if(arr[y-1][x] > height && visited[y-1][x] != height){
            visited[y-1][x] = height;
            sol(x, y-1);
        }
    }
    if(x+1 < n){
        if(arr[y][x+1] > height && visited[y][x+1] != height){
            visited[y][x+1] = height;
            sol(x+1, y);
        }
    }
    if(y+1 < n){
        if(arr[y+1][x] > height && visited[y+1][x] != height){
            visited[y+1][x] = height;
            sol(x, y+1);
        }
    }
}


int solve(){
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[j][i] > height && visited[j][i] != height){
                visited[j][i] = height;
                num++;
                // cout << i << " " << j <<" " << num << endl;
                sol(i ,j);
                safe = true;
            }
        }
    }
    return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(height = 1; height < 100; height++){
        safe = false;
        int a = solve();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // cout << visited[i][j] << " ";
                visited[i][j] = 0;
            }
            // cout << endl;
        } 
        if(a > ans){
            ans = a;
        }
        // cout << height << " " << a << endl;
        if(safe==false) break;
    }
    
    cout << ans;
}
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

int m,n,k;
int x1, y_1, x2, y2;
int arr[101][101];
vector<int> ans;
int cnt = 0;


int cal_rectangle(int i, int j){
    cnt++;
    int ret = 0;
    queue<pair<int, int>> q;
    arr[i][j] = -1;
    q.push({i,j});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        ret++;
        if(x+1 < n && arr[y][x+1] == 0){
            q.push({y,x+1});
            arr[y][x+1] = -1;
        }
        if(x-1 >= 0 && arr[y][x-1] == 0){
            q.push({y,x-1});
            arr[y][x-1] = -1;
        }
        if(y+1 < m && arr[y+1][x] == 0){
            q.push({y+1,x});
            arr[y+1][x] = -1;
        }
        if(y-1 >= 0 && arr[y-1][x] == 0){
            q.push({y-1,x});
            arr[y-1][x] = -1;
        }
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);	

    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> x1 >> y_1 >> x2 >> y2;
        for(int y = y_1; y < y2; y++){
            for(int x = x1; x < x2; x++){
                arr[y][x] = -1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                int area = cal_rectangle(i,j);
                ans.push_back(area);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for(auto i : ans){
        cout << i << ' ';
    }
	return 0; 
}
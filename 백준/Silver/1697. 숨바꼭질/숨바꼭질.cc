#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

int ans;
int n, k;
int a, a1, a2, a3, c;
queue<pair<int, int>> q;
int visited[200003];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    q.push({n,0});
    if(n==k){
        cout << 0;
        return 0;
    }
    while(!q.empty()){
        a = q.front().first;
        if(a < -3 || a > 200002 || visited[a] ==1) {
            q.pop();
            continue;
        }
        visited[a] = 1;
        c = q.front().second;
        a1 = a-1;
        a2 = a+1;
        a3 = a*2;
        if(a1 == k || a2 == k || a3 == k){
            cout << c+1;
            break;
        }
        else {
            q.push({a1,c+1});
            q.push({a2,c+1});
            q.push({a3,c+1});
        }
    }
	return 0; 
}
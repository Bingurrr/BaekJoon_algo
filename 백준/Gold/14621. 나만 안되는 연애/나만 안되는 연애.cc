#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct school{
    int x,y;
    int cost;
};

int n,m, cnt;
char sex[1020];
int parent[1020];
school arr[10010];
long long int ans;

bool cmp(school a, school b){
    return a.cost <= b.cost;
}

int find(int i){
    while(i != parent[i]){
        i = parent[i];
    }
    return i;
}   

void uni(int i, int j, int k){
    int a = find(i);
    int b = find(j);
    if(a!= b){
        parent[a] = b;
        cnt++;
        ans += k;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> m;
    for(int i= 1; i <= n; i++){
        cin >> sex[i];
        parent[i] = i;
    }
    int idx = 0;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(sex[a] != sex[b]) {
            arr[idx].x = a;
            arr[idx].y = b;
            arr[idx].cost = c;
            idx++;
        }
    }    
    sort(arr, arr+idx, cmp);
    for(int i = 0; i < idx; i++){
        uni(arr[i].x, arr[i].y, arr[i].cost);
        if(cnt == n-1) break;
    }
    if(cnt < n-1) ans = -1;
    cout << ans;
    
}
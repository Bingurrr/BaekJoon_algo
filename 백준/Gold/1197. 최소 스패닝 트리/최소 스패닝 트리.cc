#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct vertex{
    int start;
    int end;
    int cost;
};

bool cmp(vertex a, vertex b){
    return a.cost < b.cost;
}

vertex v[100001];
int n, k;
int pt[10001];
int sz[10001];
int cnt = 0;
long long int ans;

int find(int i){
    while(i != pt[i]){
        i = pt[i];
    }
    return i;
}

void uni(int p, int q, int r){
    int i = find(p);
    int j = find(q);
    if(i!=j){
        cnt++;
        ans += r;
        if(sz[i] > sz[j]){
            pt[j] = i;
            sz[i] += sz[j];
        }
        else {
            pt[i] = j;
            sz[j] += sz[i];
        }
    }
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> v[i].start >> v[i].end >> v[i].cost;
    }
    for(int i = 0; i <= n; i++) {
        pt[i] = i;
        sz[i] = 1;
    }
    int cnt = 0;
    sort(v, v+k, cmp);
    for(int i = 0; i < k; i++){
        uni(v[i].start , v[i].end, v[i].cost);
        if(cnt == n-1) break;
    }
    
    cout << ans;
    
}
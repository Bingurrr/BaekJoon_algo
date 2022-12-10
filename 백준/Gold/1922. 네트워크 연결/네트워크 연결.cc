#include <iostream>
#include <algorithm>

using namespace std;

struct computer{
    int a;
    int b;
    int cost;
};

bool cmp(computer x, computer y){
    if(x.cost >= y.cost) return false;
    return true;
}

computer com[100000];
int n, m;
int ans, cnt;
int pr[1001];

int find(int i){
    while(i != pr[i]){
        i = pr[i];
    }
    return i;
}

void uni(int p, int q, int r){
    int i = find(p);
    int j = find(q);
    if(i != j) {
        ans += r;
        cnt++;
        pr[i] = j;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> com[i].a >> com[i].b >> com[i].cost;
    }
    for(int i = 0; i < n+1; i++){
        pr[i] = i;
    }
    sort(com, com+m, cmp);
    for(int i = 0; i < m; i++){
        uni(com[i].a, com[i].b, com[i].cost);
        if(cnt==n-1) break;
    }
    cout << ans;
    return 0;
} 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#define INF 50000000
using namespace std;

struct T{
    int a,b,c;
    T(int x, int y, int z) : a(x), b(y), c(z) {}
};

int testcase;
int n, m, w;
int s, e, t;
int value[502];
vector<T> r;
void solve(){
    for(int i = 1; i <= 501; i++){
        value[i] = INF;
    }
    value[1] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < r.size(); j++){
            int from = r[j].a;
            int to = r[j].b;
            int cost = r[j].c;
            if(value[to] > value[from] + cost){
                value[to] = value[from] + cost;
            }
        }
    }
    for(int i = 0; i < 2*m+w; i++){
        int from = r[i].a;
        int to = r[i].b;
        int cost = r[i].c;
        if(value[to] > value[from] + cost){
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> testcase;
    for(int i = 0; i < testcase; i++){
        memset(value, -1, sizeof(value));
        r.clear();
        cin >> n >> m >> w;
        for(int j = 0; j < m; j++){
            cin >> s >> e >> t;
            r.push_back(T(s,e,t));
            r.push_back(T(e,s,t));
        }
        for(int j = 0; j < w; j++){
            cin >> s >> e >> t;
            r.push_back(T(s,e,-t));
        }
        solve();
    }
    
	return 0; 
}

#include <iostream>
#include <set>
#include <queue> 
#define MAX 1001

using namespace std;

int n, m, a, b;
int f[502][502];
int ans;
queue<int> q;
set<int> s;


void solve(){
    for(int i = 2; i < n+1; i++){
        if(f[1][i] == 1 ){
            q.push(i);
            s.insert(i);
        }
    }
    // cout << s.size() << endl;;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = 2; i < n+1; i++){
            if(f[t][i] == 1){
                s.insert(i);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        f[a][b] = 1;
        f[b][a] = 1;
    }
    solve();
    cout << s.size();
    
    
    return 0;
} 
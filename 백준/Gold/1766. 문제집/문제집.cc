#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b;
vector<vector <int>> v;
vector<int> ans;
int cnt[32002];
priority_queue< int, vector<int>, greater<int> > q;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >>  m;
    v.assign(n + 1, vector<int>(0, 0));
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cnt[b]++;
        v[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()){
        int k = q.top();
        ans.push_back(k);
        q.pop();
        for(int i = 0; i < v[k].size(); i++){
            int t = v[k][i];
            // cout << i << " " << t << endl;
            cnt[t]--;
            if(cnt[t] == 0){
                q.push(t);
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
}
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, t, m, a;
int ans = 1;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int,int>>> pq;
        queue<pair<int,int>> q;
        ans = 1;
        for(int j = 0; j < n; j++){
            cin >> a;
            pq.push(make_pair(a, j));
            q.push(make_pair(a,j));
        }
        while(!q.empty()){
            // cout << pq.top().first << " " << q.front().second << endl;
            if(pq.top().first == q.front().first){
                if(q.front().second == m){
                    break;
                }
                pq.pop();
                q.pop();
                ans++;
            }
            else{
                int k = q.front().first;
                int s = q.front().second;
                q.pop();
                q.push(make_pair(k,s));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int s, f;
int a, b, c, ans;
long long int total;

vector<pair<short,short>> road[10001];
vector<pair<short,short>> rec_road[10001];
queue<pair<short,int>> q;
queue<pair<int, int>> qu;
int times[10001];
// queue<vector<short>> cnt;
set<short> roads;

void count_country(){
    queue<pair<int, int>> qu;
    qu.push(make_pair(f,0));
    bool visited[10001];
    memset(visited, 0, sizeof(visited));
    visited[f] = true;

    while(!qu.empty()){
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();
        for(auto i : rec_road[x]){
            int nex = i.first;
            int cost = i.second + y;

            if(total - cost == times[nex]){
                if(!visited[nex]){
                    visited[nex] = true;
                    ans++;
                    qu.push(make_pair(nex, cost));
                }
                else ans++;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        road[a].push_back(make_pair(b,c));
        rec_road[b].push_back(make_pair(a,c));
    }
    cin >> s >> f;
    times[s] = 0;
    // for(auto i : road[s]){
        // q.push(i);
        // vector<short> t;
        // t.push_back(s);
        // cnt.push(t);
    // }
    q.push({s,0});
    while(!q.empty()){
        int k = q.front().first;
        for(auto i : road[k]){
            if(i.first == f){
                if(total < q.front().second + i.second){
                    total = q.front().second + i.second;
                    times[i.first] = total;
                }
            }
            else{
                int t = i.second+q.front().second;
                if(times[i.first] < t){
                    times[i.first] = t;
                    q.push(make_pair(i.first, t));
                }
            }
        }
        q.pop();
    }
    count_country();
    cout << total << '\n' << ans;
    return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#define MAX 987654321

using namespace std;

int n, m, num;
int ans = MAX;

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> sel;

bool visited[14];


int distance(pair<int, int> a, pair<int, int> b){
    return abs(a.first-b.first) + abs(a.second - b.second);
}

int total_distance(){
    int ret = 0;
    for(unsigned int i = 0; i < home.size(); i++){
        int dist = MAX;
        for(unsigned int j = 0; j < sel.size(); j++){
            dist = min(dist, distance(home[i], sel[j]));
        }
        ret += dist;
    }
    return ret;
}

void solve(int idx, int k){
    if(k == m){
        ans = min(ans, total_distance());
        return;
    }
    for(unsigned int i = idx; i < chicken.size(); i++){
        if(visited[i] == true) continue;
        else {
            visited[i] = true;
            sel.emplace_back(chicken[i]);
            solve(i,k+1);
            visited[i] = false;
            sel.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // input
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            if(num == 1){
                home.push_back({i,j});
            }
            else if(num == 2){
                chicken.push_back({i,j});
            }
        }
    }
    // dfs 조합만들기
    solve(0,0);
    
    cout << ans;
    
    return 0;
}

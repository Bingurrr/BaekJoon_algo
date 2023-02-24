#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 987654321

using namespace std;

int n,x;
int ans[1000001];
vector<pair<int,int>> v;
bool cmp(pair<int,int> a, pair<int, int> b){
    return a.second < b.second;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back({i,x});
    }
    sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    // 시작
    ans[v[0].first] = cnt;
    
    
    for(int i = 1; i < n; i++){
        int idx = v[i].first;
        if(v[i-1].second != v[i].second){
            cnt++;
        }
        ans[idx] = cnt;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    
	return 0;
}

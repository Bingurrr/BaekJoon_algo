#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#include <stack>
#include <regex>
#define INF (1 << 30)

using namespace std;

int n;
int d, p;
int arr[10001];
long long int ans;
vector <pair<int, int>> v;
priority_queue <int, vector<int>, greater<int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> p >> d;
        v.push_back({d,p});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        q.push(v[i].second);
        if(q.size() > v[i].first) q.pop();
    }
    while(!q.empty()){
        ans += q.top();
        q.pop();
    }
    cout << ans;
    
    return 0;
}



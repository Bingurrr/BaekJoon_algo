#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>


using namespace std;

int n,s,e,a,b, ans;
vector<pair<int, int>> v;
// vector<int> vec;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(pair<int, int> x, pair<int,int> y){
    if (x.first != y.first)
        return x.first < y.first;
    else{
        return x.second < y.second;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ans = 1;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);
    pq.push(v[0].second);
    for(int i = 1; i < v.size(); i++){
        if(pq.top() > v[i].first){
            ans++;
            pq.push(v[i].second);
        }
        else{
            pq.pop();
            pq.push(v[i].second);
        }
    }
    cout << ans;
	return 0; 
}

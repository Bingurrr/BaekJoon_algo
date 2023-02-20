#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

int n, k;
int last_value, cnt;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int ans[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);	
	cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        pq.push({k,i});
    }
    while(!pq.empty()){
        int t = pq.top().first;
        int s = pq.top().second;
        pq.pop();
        if(t==last_value){
            ans[s] = cnt-1;
            continue;
        }
        else{
            last_value = t;
            ans[s] = cnt;
            cnt++;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

	return 0; 
}
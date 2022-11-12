#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

int n, a, b;
vector<pair<int, int>> v;
long long int ans;
int day;


bool cmp(pair<int,int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end(), cmp);
    day = v[0].first;
    while(day != 0){
        priority_queue<int, vector<int>, less<int>> heap;
        for(int i = 0; i < v.size(); i++){
            if(v[i].first < day) break;
            heap.push(v[i].second);
        }
        ans += heap.top();
        //cout << heap.top() << endl;
        for(int j = v.size()-1; j >=0; j--){
            if(v[j].first >= day && heap.top() == v[j].second){
                v[j].second = 0;
                break;
            }
        }
        day--;
    }
    cout << ans;
}
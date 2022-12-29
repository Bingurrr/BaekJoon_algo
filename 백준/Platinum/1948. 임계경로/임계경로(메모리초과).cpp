#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
using namespace std;

int n, m;
int s, f;
int a, b, c;
long long int total;

vector<pair<short,short>> road[10001];
queue<pair<short,int>> q;
queue<vector<short>> cnt;
set<short> roads;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        road[a].push_back(make_pair(b,c));
    }
    cin >> s >> f;
    for(auto i : road[s]){
        q.push(i);
        vector<short> t;
        t.push_back(s);
        cnt.push(t);
    }
    while(!q.empty()){
        int k = q.front().first;
        for(auto i : road[k]){
            if(i.first == f){
                if(total < q.front().second + i.second){
                    total = q.front().second + i.second;
                    roads.clear();
                    roads.insert(s);
                    roads.insert(f);
                    roads.insert(k);
                    for(auto j : cnt.front()){
                        roads.insert(j);
                    }
                }
                else if(total == q.front().second + i.second){
                    roads.insert(k);
                    for(auto j : cnt.front()){
                        roads.insert(j);
                    }
                }
            }
            else{
                q.push(make_pair(i.first, i.second+q.front().second));
                vector<short> t = cnt.front();
                t.push_back(k);
                cnt.push(t);
            }
        }
        cnt.pop();
        q.pop();
    }
    cout << total << '\n';
    cout << roads.size() << '\n';
    return 0;
}

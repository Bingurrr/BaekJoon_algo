#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


int n, k;
string s;
deque<char> q;


void solve(){
    for(int i = 0; i < s.length(); i++){
        while(k && !q.empty() && q.back() < s[i]){
            k--;
            q.pop_back();
        }
        q.push_back(s[i]);
    }
    for(int i = 0; i < q.size() - k; i++){
        cout << q[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cin >> s;
    solve();
    return 0;
}

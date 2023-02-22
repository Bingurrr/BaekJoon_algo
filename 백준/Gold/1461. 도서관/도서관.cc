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

int n, m, x, ans;
vector<int> v1; // 음수
vector<int> v2; // 양수
int sum1, sum2;

bool cmp(int a, int b){
    return a > b;
}

void sum_negative(){
    // int k = v1.size() % m;
    for(unsigned int i = 0; i < v1.size(); i+=m){
        ans += 2*abs(v1[i]);
        // cout << ans << endl;
    }
}

void sum_positive(){
    // int k = v2.size() % m;
    for(unsigned int i = 0; i < v2.size(); i+= m){
        ans += 2*v2[i];
        // cout << ans << endl;
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > 0) v2.push_back(x);
        else v1.push_back(x);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), cmp);

    // cout << v2[0] << endl;
    
    sum_negative();
    sum_positive();
    if(v1.size() > 0 && v2.size() > 0){
        if(abs(v1[0]) > v2[0]) ans += v1[0];
        else ans -= v2[0];
    }
    else if(v1.size() > 0){
        ans += v1[0];
    }
    else ans -= v2[0];

    
    cout << ans;
    
	return 0;
}

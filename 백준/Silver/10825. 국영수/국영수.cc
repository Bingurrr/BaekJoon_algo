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

struct score{
    string name;
    int k, e, m;
};

bool cmp(score a, score b){
    // cout << a.k << b.k << endl;
    if(a.k < b.k){
        return false;
    }
    else if (a.k > b.k){
        return true;
    }
    else if(a.e > b.e){
        return false;
    }
    else if(a.e < b.e){
        return true;
    }
    else if(a.m > b.m){
        return true;
    }
    else if(a.m < b.m){
        return false;
    }
    else {
        return a.name < b.name;
    }
}

vector<score> v; 
vector<string> ans;

score x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x.name >> x.k >> x.e >> x.m;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);

    score a;
    // a.name = "Taewhan";
    // a.k = 50;
    // a.e = 60;
    // a.m = 90;
    // score b;
    // b.name = "Donghyuk";
    // b.k = 50;
    // b.e = 60;
    // b.m = 100;

    // cmp(a,b);
    
    for(int i = 0; i < n; i++){
        cout << v[i].name << '\n';
    }


    return 0;
}



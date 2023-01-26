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

int n;
string s;
int ans = -987654321;


int cal(char oper, int a, int b){
    //cout << oper << endl;
    if(oper == '+')
        return a+b;
    
    if(oper == '*')
        return a*b;
    
    if(oper == '-')
        return a-b;

    // error
    else return -1;
}


void solve(int idx, int val){
    //cout << idx << " " << val << endl;
    
    if(idx >= n){
        ans = max(ans, val);
        return;
    }

    char oper;
    if(idx == 0) oper = '+';
    else {
        oper = s[idx-1];
    }

    if(idx + 2 < n){
        int k = cal(s[idx+1], s[idx]-'0', s[idx+2]-'0');
        solve(idx+4, cal(oper, val, k));
    }
    solve(idx+2, cal(oper, val, s[idx]-'0'));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    cin >> s;
    
    solve(0,0);
    
    cout << ans;
    
    return 0;
}
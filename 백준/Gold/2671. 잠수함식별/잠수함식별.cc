#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#define MAX 987654321

using namespace std;


string s;

//(110~1~ | | 01)~
// 100~1~ -> 100으로 시작해서 1로
// 01 -> 0으로시작
// -> 1로 시작하면 100이 나와야하고 0으로 시작하면 01


int dp[151];
int sol(int n){
    if(n==s.size()) return 1;
    int& ret = dp[n];
    if(ret!=-1) return ret;
 
    if(n>=s.size()-1) return ret=0;
    string t = s.substr(n,2);
 
    if(t=="01" && sol(n+2)) return ret=1;
    if(n>=s.size()-3) return ret=0;
    t = s.substr(n,3);
 
    if(t=="100"){
        int i;
        for(i=n+3;i<s.size();i++){
            if(s[i]=='1') break;
        }
        for(int j=i;j<s.size();j++){
            if(s[j]!='1') break;
            else if(sol(j+1)) return ret=1;
        }
    }
    return ret=0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    memset(dp,-1,sizeof(dp));
    if(sol(0)) cout << "SUBMARINE";
    else cout << "NOISE";
}


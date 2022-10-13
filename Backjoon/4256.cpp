#include <iostream>
#include <cmath>
using namespace std;

int t, n;
int pre[1001];
int in[1001];
int post[1001];
int idx;
void solve(int s1,int e1,int s2, int e2){
    if(s1>e1 || s2 >e2) return;
    int rt = pre[s1];
    post[idx] = rt;
    idx--;
    int cnt = 0;
    while(rt != in[s2]) {
        cnt++;
        s2++;
    }
    
    solve(s1+cnt+1, e1, s2+1, e2);
    solve(s1+1,s1+cnt, s2-cnt, s2-1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        idx = n-1;
        for(int j = 0; j < n; j++) cin >> pre[j];
        for(int j = 0; j < n; j++) cin >> in[j];
        solve(0,n-1,0,n-1);
        for(int j = 0; j < n; j++) cout << post[j] << " ";
        cout << endl;
    }
    return 0;
}

#include<iostream>
#include<algorithm>

using namespace std;

int n, ans;
char s[102];

int str_len(char s[]){
    int l = 0;
    while(s[l] != '\0'){
        l++;
    }
    return l;
}

int solve(){
    int visited[27] = {0,};
    int a = s[0] - 'a';
    visited[a] = 1;
    for(int i = 1; i < str_len(s); i++){
        if(s[i] == s[i-1]) continue;
        int t = s[i] - 'a';
        if(visited[t] == 1) return 0;
        else visited[t] = 1;
    }
    return 1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        ans += solve();
    }
    cout << ans;
}
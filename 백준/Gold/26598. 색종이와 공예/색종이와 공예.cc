#include<iostream>

using namespace std;

int n, m;
char s[1001][1001];

bool is_rectangle(int a, int b){
    char c = s[a][b];
    if(a==n-1){
        a = n-2;
    }
    if(b == m-1){
        b = m-2;
    }

    int cnt = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(c == s[a+i][b+j]) cnt++;
        }
    }
    if(cnt==3) return false;
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool a = is_rectangle(i,j);
            if(a==false){
                cout << "BaboBabo";
                return 0;
            }
        }
    }
    cout << "dd";
    
    
    return 0;
}
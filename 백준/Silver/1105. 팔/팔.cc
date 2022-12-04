#include <iostream>

using namespace std;
int ans;

char n[100];
char m[100];

int str_len(char *arr){
    int l=0;
    for(int i = 0; i < 20; i++){
        if(arr[i] == '\0') break;
        else l++;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < str_len(n); i++){
        if(n[i] == m[i]){
            if(n[i]=='8')
                ans++;
        }
        else {
            break;
        }
    }
    if(str_len(n) != str_len(m)) ans = 0;
    cout << ans;
    return 0;
} 
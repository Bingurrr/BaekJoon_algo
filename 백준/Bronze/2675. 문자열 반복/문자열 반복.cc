#include<iostream>

using namespace std;

int n, k;
char s[21];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k >> s;
        int idx = 0;
        while(s[idx] != '\0'){
            for(int j = 0; j < k; j++){
                cout << s[idx];
            }
            idx++;
        }
        cout << '\n';
    }
    return 0;
}
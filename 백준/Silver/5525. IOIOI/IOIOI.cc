#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

long long int n, m;
string s;
long long int ans;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < m; i++){
        int cnt = 0;
        if(s[i] == 'O') continue;
        else{
            while(s[i+1] == 'O' && s[i+2] == 'I'){
                cnt++;
                if(cnt==n) {
                    cnt--;
                    ans++;
                }
                i+=2;
            }
        }
        cnt = 0;
    }
    cout << ans;
	return 0; 
}
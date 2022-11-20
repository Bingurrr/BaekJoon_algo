#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 100001

using namespace std;

char ch[MAX];
int n;
long long int ans= MAX;
int cnt[5];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> ch;
    for(int i = 0; i < n; i++){
        if(ch[i]=='H'){
            cnt[0]++;
        }
        else if(ch[i]=='I'){
            cnt[1]++;
        }
        else if(ch[i] == 'A'){
            cnt[2]++;
        }
        else if(ch[i]=='R'){
            cnt[3]++;
        }
        else if(ch[i]=='C'){
            cnt[4]++;
        }
    }
    for(int i = 0; i < 5; i++){
        // cout << cnt[i] << endl;
        if(ans > cnt[i]){
            ans = cnt[i];
        }
    }
    cout << ans;
	return 0;
}
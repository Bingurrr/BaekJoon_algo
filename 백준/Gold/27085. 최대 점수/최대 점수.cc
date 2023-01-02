#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

int n, s;
int arr[200002];
long long int ans;
long long int score;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);	
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    s--;
    int l = s;
    int r = s;
    long long int ls = 0;
    long long int rs = 0;
    while(l >= 0 || r <= n){
        if(l >=0){
            if(ls+score >= 0){
                ls += arr[l];
                if(ls >= 0) {
                    score += ls;
                    ls = 0;
                    if(ans < score) ans = score;
                }
                l--;
            }
        }
        if(r <= n){
            if(rs + score >= 0){
                rs += arr[r];
                if(rs >= 0) {
                    score += rs;
                    rs = 0;
                    if(ans < score) ans = score;
                }
                r++;
            }
        }
        if((rs+score < 0 && ls+score <0) || (l<0 && rs+score < 0) || (r >=n &&ls+score <0)) break;
    }
    cout << ans;
	return 0; 
}
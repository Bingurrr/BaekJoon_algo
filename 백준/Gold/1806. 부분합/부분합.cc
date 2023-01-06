#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001]; 
int N, M;
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> arr[i];
    int st=1, en=1, total = arr[1], ans = 987654321;
    while(st <= en && en <= N){
        if(total >= M) ans = min(ans, (en-st+1));
        if(total < M) {
            en++; 
            total += arr[en];
        } else {
            total -= arr[st];
            st++;
        }
    }
    if(ans == 987654321) cout << "0";
    else cout << ans;
}
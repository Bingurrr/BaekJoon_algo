#include <iostream>
#include <cmath>
using namespace std;

int n;
int ans;
int prime[2000000];

bool is_prime(int k){
    for(int i = 3; i <= sqrt(k); i+=2){
        if(k%i==0) return false;
    }
    return true;
}


int main(){
    cin >> n;
    prime[0] = 2;
    prime[1] = 3;
    int idx = 2;
    for(int i = 5; i <= n; i += 2){
        if(is_prime(i)){
            prime[idx] = i;
            idx++;
        }
    }
    int s = 0;
    int start = 0;
    int end = 0;
    while(start != idx && end <= idx){
        if(s == n ){
            ans++;
            s = s - prime[start];
            start++;
        }
        else if(s > n){
            s = s - prime[start];
            start++;
        }
        else {
            s = s + prime[end];
            end++;
        }
    }
    // for(int i = 0; i < idx; i++){
    //     cout << prime[i] << " ";
    // }
    // cout << endl;
    cout << ans;
}
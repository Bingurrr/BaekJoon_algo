#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


long long int n, m;
long long int min_value, sum_value;

int is_prime(int k){
    if(k==1) return -1;
    for(int i = 2; i<= sqrt(k); i++){
        if(k%i==0){
            return -1;
        }
    }
    return k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = n; i <= m; i++){
        int t = is_prime(i);
        // cout << t << endl;
        if(t != -1 && min_value == 0){
            min_value = t;
        }
        if(t != -1){
            sum_value += t;    
        }
    }
    
    if(min_value == 0){
        cout << -1;
    }
    else{
        cout << sum_value << '\n';
        cout << min_value << '\n';
    }
}

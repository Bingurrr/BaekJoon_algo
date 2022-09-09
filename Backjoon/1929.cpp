#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num){
    if(num ==1){
        return false;
    }
    else if(num == 2){
        return true;
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
    
}

int main() {
    int m,n;
    cin >> m >> n;
    if (m==2 || (m==1 && n >= 2)){
        cout << 2 << '\n';
    }
    if (m%2 == 0){
        m++;
    }
    for(int i = m; i <= n; i = i+2){
        if(is_prime(i)){
            cout << i << '\n';
        }
    }
    return 0;
    
}

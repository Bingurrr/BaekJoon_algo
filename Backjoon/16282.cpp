#include <iostream>
#include <cmath>
using namespace std;

long long int n;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    long long int k = 1;
    int ans = 0;
    while(((k+1)* (long long)pow(2,k+1)-1 ) < n ){
        k++;
    }
    cout << k;
    return 0;
}

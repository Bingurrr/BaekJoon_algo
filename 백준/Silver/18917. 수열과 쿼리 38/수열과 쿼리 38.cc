#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 500003

using namespace std;

int n;
int a, b;

long long int sum;
long long int xr;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a == 1) {
            cin >> b;
            sum += b;
            xr^=b;
        }
        else if(a==2){
            cin >> b;
            sum -= b;
            xr ^=b;
        }
        else if(a==3){
            cout << sum << '\n';
        }
        else {
            cout << xr << '\n';
        }
    }
}
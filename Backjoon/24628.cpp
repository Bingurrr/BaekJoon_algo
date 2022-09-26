#include <iostream>
#include <cmath>
using namespace std;

long long int at = 0;
int t;
int n;

double sqrt_num(int num){
    double ret = num;
    for(float i = 31; i >= 2; i--){
        double k = pow(num, 1.0/i);
        int a = round(k);
        //cout << k << " " << k-double(a) << endl;
        if((abs(k-double(a)) < 0.0000000001)){
            return k;
        }
    }
    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        if(n == 1){
            at++;
        }    
        else {
            at += sqrt_num(n)+0.5;
        }
    }
    cout  << at;
    return 0;
}

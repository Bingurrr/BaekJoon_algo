#include <iostream>
#include <cmath>
#include <algorithm>
#define M 1234567891

using namespace std;

long long int a, b, c;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(true){
        cin >> a >> b >> c;
        if(a*b*c == 0) break;
        a = a * a;
        b = b* b;
        c = c * c;
        if(a+b==c||a+c==b||b+c==a){
            cout << "right" << '\n';
        }
        else {
            cout << "wrong" << "\n";
        }
    }
    
    return 0;
}
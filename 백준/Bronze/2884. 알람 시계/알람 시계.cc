#include <iostream>

using namespace std;
int a, b;
int main(void){
    
    cin >> a >> b;
    
    if(b < 45){
        b += 15;
        a--;
    }
    else
        b -= 45;
    
    if(a < 0)
        a = 23;
    
    cout << a << " "<< b;
}
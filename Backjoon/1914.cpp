#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int n;

void hanoi(int n, int a, int b, int c){
    if(n > 0) {
        hanoi(n-1, a, c, b);
        cout << a << " " << c << '\n';
        hanoi(n-1, b, a, c);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    string ret = to_string(pow(2,n));
    int x = ret.find('.');			
	ret = ret.substr(0, x);				
	ret[ret.length() - 1] -= 1;	
    cout << ret << endl;
    if(n <= 20) hanoi(n,1,2,3);
    return 0;
    
}

#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX 100001


using namespace std;

int a,b,c,d,e;
int x;
int ans;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> a >> b >> c >> d >> e;
    x = b;

    while(a != 0){
        ans++;
        if(x+d > c && (c-b) < d) {
            cout << -1;
            return 0;
        }
        if(x+d > c){
            x -= e;
            if(x < b){
                x = b;
            }
        }
        else {
            a--;
            x = x +d;
        }
        
    }
    cout << ans;
	
	return 0;
}
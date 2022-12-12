#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int n;
int a,b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cout << a+b << '\n';
    }
}
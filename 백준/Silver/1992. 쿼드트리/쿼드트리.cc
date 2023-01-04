#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

int n;
char arr[65][65];
char ans;

void solve(int x, int y, int gap){
    char s = arr[y][x];
    for(int i = y; i < y+gap; i++){
        for(int j = x; j < x+gap; j++){
            if(arr[i][j] != s){
                cout<< '(';
                solve(x,y, gap/2);
                solve(x+gap/2,y, gap/2);
                solve(x,y+gap/2, gap/2);
                solve(x+gap/2,y+gap/2, gap/2);
                cout << ')';
                return;
            }
        }
    }
    cout << s;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    solve(0,0,n);
    
    return 0; 
}

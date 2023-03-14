#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int T;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T;t++){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int rx, ry; 
        if(x > y){ 
            rx = x - y + 1;
            ry = 1;
        }
        else{
            ry = y - x + 1;
            rx = 1;
        }
 
        int cnt = 1; 
        int nx = 1; 
        int ny = 1; 
        bool stop = false; 
        while(!stop){
            if(nx == rx && ny == ry){ 
                cnt = cnt + x - rx; 
                nx = x;
                ny = y;
                stop = true;
            }        
            else if(m - nx < n - ny){
                ny = ny + m - nx + 1;
                cnt = cnt + m - nx + 1;
                nx = 1;  
            }
            else if(m - nx > n- ny){
                nx = nx + n - ny + 1;
                cnt = cnt + n - ny + 1;
                ny = 1;
            }
            else{ 
                cnt = cnt + n - ny;
                nx = m;
                ny = n;
                stop = true;
            }
        }
        if(nx == x && ny == y){ 
            cout << cnt << endl;
        }
        else{ 
            cout << -1 << endl;
        }
    }
    return 0;
}


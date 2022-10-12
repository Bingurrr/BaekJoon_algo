#include <iostream>
#include <cmath>
using namespace std;

long long int l,w,h;
long long a, b, n;
long long int arr[21];
long long int cnt;
long long volum;
long long int p[20] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
void solve(int x, int y, int z){
    if(x <=0 || y <=0 || z <=0) return;
    for(int i = 19; i >= 0; i--){
        long long int k = p[i];
        if(arr[i] > 0 &&k <= x && k <= y && k <= z){
            //cout << 'k' << k << endl;
            cnt++;
            arr[i]--;
            volum += k*k*k;
            // solve(x-k,y,z);
            // solve(k,y-k,z);
            // solve(k,k,z-k);
            if(x>y && x>z){
                solve(x-k,y,z);
                solve(k,y-k,z);
                solve(k,k,z-k);
                
            }
            else if(y>x && y > z){
                solve(x,y-k,z);
                solve(x-k,k,z);
                solve(k,k,z-k);
            }
            else {
                solve(x,y,z-k);
                solve(x,y-k,k);
                solve(x-k,k,k); 
            }
            break;
        }
    }
    
}

int main(){
    cin >> l >> w >> h;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        arr[a] = b;
    }
    solve(l,w,h);
    long long v = l*w*h;
    //cout << cnt << " " << volum << endl;
    if(volum != v) cnt = -1;
    cout << cnt;
    return 0;
}

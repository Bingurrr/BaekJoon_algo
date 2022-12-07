#include <iostream>

using namespace std;

int w, h;
int land[51][51];
int ans = 2;

void solve(int x, int y){
    if(x+1 < w){
        if(land[y][x+1] == 1){
            land[y][x+1] = ans;
            solve(x+1,y);
        }
        if(y+1 < h){
            if(land[y+1][x+1] == 1){
                land[y+1][x+1] = ans;
                solve(x+1, y+1);
            }
        }
        if(y-1 >= 0) {
            if(land[y-1][x+1]==1){
                land[y-1][x+1] = ans;
                solve(x+1,y-1);
            }
        }
    }
    if(y+1 < h){
        if(land[y+1][x] == 1){
            land[y+1][x] = ans;
            solve(x,y+1);
        }
        if(x-1 >= 0){
            if(land[y+1][x-1]==1){
                land[y+1][x-1] = ans;
                solve(x-1,y+1);
            }
        }
    }
    if(x-1 >= 0){
        if(land[y][x-1] == 1){
            land[y][x-1] = ans;
            solve(x-1,y);
        }
        if(y-1 >= 0){
            if(land[y-1][x-1] == 1){
                land[y-1][x-1] = ans;
                solve(x-1, y-1);
            }
        }
    }
    if(y-1 >= 0){
        if(land[y-1][x] == 1){
            land[y-1][x] = ans;
            solve(x,y-1);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> w >> h){
        if(w==0 && h==0) break;
        else {
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    cin >> land[i][j];
                }
            }
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(land[i][j] == 1){
                        land[i][j] = ans;
                        solve(j,i);
                        ans++;
                    }
                }
            }
            // for(int i = 0; i < h; i++){
            //     for(int j = 0; j < w; j++){
            //         cout << land[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            cout << ans-2 << "\n";
            ans = 2;
        }
    }
    return 0;
} 
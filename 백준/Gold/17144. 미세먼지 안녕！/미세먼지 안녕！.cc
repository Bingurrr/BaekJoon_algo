#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 987654321

using namespace std;

int r, c, t;
int room[1001][1001];
int dust[1001][1001];

int x, y, ans;

int count_direction(int i, int j){
    int cnt = 4;
    
    if(i-1 < 0 || room[i-1][j] == -1) cnt--;
    if(i+1 >= r || room[i+1][j] == -1) cnt--;
    if(j-1 < 0 || room[i][j-1] == -1) cnt--;
    if(j+1 >= c || room[i][j+1] == -1) cnt--;
    return cnt;
}

void move_dust(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] <= 4) continue;
            
            int cnt = count_direction(i,j);
            int move_dust = room[i][j]/5;

            // dust에 저장하기 -> 이동하는 먼지
            if(i-1 >= 0 && room[i-1][j] != -1) {
                dust[i-1][j] += move_dust;
            }
            if(i+1 < r && room[i+1][j] != -1) {
                dust[i+1][j] += move_dust;
            }
            if(j-1>= 0 && room[i][j-1] != -1) {
                dust[i][j-1] += move_dust;
            }
            if(j+1 < c && room[i][j+1] != -1) {
                dust[i][j+1] += move_dust;
            }
            // 이동한 먼지 제거
            dust[i][j] -= move_dust*cnt;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            room[i][j] += dust[i][j];
            dust[i][j] = 0;
        }
    }

}

void air_cleaner(){
    // 공기청정기 상단부분
    int air_x = x-2;
    int air_y = y;
    room[air_x][y] = 0;
    while(air_x-1 >= 0){
        room[air_x][air_y] = room[air_x-1][y];
        air_x--;
    }
    while(air_y+1 < c){
        room[air_x][air_y] = room[air_x][air_y+1];
        air_y++;
    }
    while(air_x+1 < x){
        room[air_x][air_y] = room[air_x+1][air_y];
        air_x++;
    }
    while(air_y-1 > y){
        room[air_x][air_y] = room[air_x][air_y-1];
        air_y--;
    }
    room[x-1][y+1] = 0;

    
    // 공기청정기 하단부분
    int air_x2 = x;
    int air_y2 = y;
    
    room[air_x2+1][air_y2] = 0;
    air_x2++;
    while(air_x2+1 < r){
        room[air_x2][air_y2] = room[air_x2+1][air_y2];
        air_x2++;
    }
    while(air_y2+1 < c){
        room[air_x2][air_y2] = room[air_x2][air_y2+1];
        air_y2++;
    }
    while(air_x2-1 >= x){
        room[air_x2][air_y2] = room[air_x2-1][air_y2];
        air_x2--;
    }
    while(air_y2-1 > y){
        room[air_x2][air_y2] = room[air_x2][air_y2-1];
        air_y2--;
    }
    room[x][y+1] = 0;
    
    
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> t;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> room[i][j];
            if(room[i][j] == -1){
                x = i;
                y = j;
            }
        }
    }
    
    while(t > 0){
        t--;
        move_dust();
        air_cleaner();
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] > 0) ans+= room[i][j];
        }
    }
    cout << ans;
	return 0;
}

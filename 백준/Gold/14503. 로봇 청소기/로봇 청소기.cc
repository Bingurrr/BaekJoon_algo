#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


#define MAX 50


int N, M;
int visited_count;
int map[MAX][MAX];
int visited[MAX][MAX] = {
    0,
}; 

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int r, c, d;

void Input()
{
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    visited[r][c] = 1;
    visited_count++;
}

void dfs(){

    for (int i = 0; i < 4; i++){
        int next_d = (d + 3 - i) % 4;
        int next_r = r + dx[next_d];
        int next_c = c + dy[next_d];

        if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M || map[next_r][next_c] == 1){
            continue;
        }


        if (map[next_r][next_c] == 0 && visited[next_r][next_c] == 0)
        {
            visited[next_r][next_c] = 1;
            r = next_r;
            c = next_c;
            d = next_d;
            visited_count++;
            dfs();
        }
    }

    int back_idx = d > 1 ? d - 2 : d + 2;
    int back_r = r + dx[back_idx];
    int back_c = c + dy[back_idx];
    if (back_r >= 0 && back_r <= N || back_c >= 0 || back_c <= M){
        if (map[back_r][back_c] == 0)
        {
            r = back_r;
            c = back_c;
            dfs();
        }
        else
        {
            cout << visited_count << endl;
            exit(0);
        }
    }
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Input();
    dfs();

    return 0;
}
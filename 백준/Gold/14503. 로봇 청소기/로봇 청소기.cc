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
int map[MAX][MAX]; // 지도
int visited[MAX][MAX] = {
    0,
}; // 청소기 경로,  방문했으면 1

// 북, 동, 남, 서
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

void dfs()
{
    // 네 방향 청소, 계속 왼쪽으로 회전
    for (int i = 0; i < 4; i++)
    {
        int next_d = (d + 3 - i) % 4; // next direction (왼쪽)
        int next_r = r + dx[next_d];
        int next_c = c + dy[next_d];

        // B. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
        if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M || map[next_r][next_c] == 1)
        {
            continue;
        }

        // A. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
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
    // C. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는,
    if (back_r >= 0 && back_r <= N || back_c >= 0 || back_c <= M)
    {
        // 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
        if (map[back_r][back_c] == 0)
        {
            r = back_r;
            c = back_c;
            dfs();
        }
        // D. 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
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
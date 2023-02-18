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
#define MAX 29

using namespace std;

int N;
double Percent[4];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    cin >> N;
    for (int i = 0; i < 4; i++)
    {
        int a; cin >> a;
        Percent[i] = a / 100.0;
    }        
}
 
double DFS(int x, int y, int Cnt)
{
    if (Cnt == N) return 1.0;
 
    Visit[x][y] = true;
    double Result = 0.0;
 
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (Visit[nx][ny] == true) continue;
        Result = Result + Percent[i] * DFS(nx, ny, Cnt + 1);
    }
 
    Visit[x][y] = false;
    return Result;
}
 
void Solution()
{
    double R = DFS(14, 14, 0);
    cout.precision(10);
    cout << fixed << R << '\n';
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
 
    return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#include <stack>
#include <regex>
#define INF (1 << 30)
#define endl "\n"
using namespace std;



struct step
{
	int Rx, Ry;
	int Bx, By;
	int Count;
};

char arr[11][11];
bool visit[11][11][11][11];
int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void move(int& rx, int& ry, int& distance, int& i)
{
	while (arr[rx + dx[i]][ry + dy[i]] != '#' && arr[rx][ry] != 'O')
	{
		rx += dx[i];
		ry += dy[i];
		distance += 1;
	}
}

void BFS(int Rx, int Ry, int Bx, int By)
{
	queue<step> q;
	q.push({ Rx,Ry,Bx,By,0 });
	visit[Rx][Ry][Rx][Ry] = true;
	while (!q.empty())
	{
		int rx = q.front().Rx;
		int ry = q.front().Ry;
		int bx = q.front().Bx;
		int by = q.front().By;
		int count = q.front().Count;
		q.pop();

		if (count >= 10) break;

		for (int i = 0; i < 4; i++)
		{
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, ncount = count + 1;

			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);

			if (arr[nbx][nby] == 'O') continue;
			if (arr[nrx][nry] == 'O')
			{
				cout << ncount;
				return;
			}

			if (nrx == nbx && nry == nby)
			{
				if (rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}

			if (visit[nrx][nry][nbx][nby]) continue;
			visit[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,ncount });
		}
	}
	cout << -1;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
	int Rx = 0, Ry = 0, Bx = 0, By = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
			{
				Rx = i; Ry = j;
			}
			else if (arr[i][j] == 'B')
			{
				Bx = i; By = j;
			}
		}
	}
	BFS(Rx, Ry, Bx, By);
	return 0;
    
}




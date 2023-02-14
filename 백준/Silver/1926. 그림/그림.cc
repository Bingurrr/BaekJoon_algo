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

using namespace std;


queue<pair<int,int> > Q;
int n,m;
int area = 0; 
int max = 0; 
int num = 0;
int arr[501][501];
bool chk[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<int,int> > Q;
	int n,m;

	cin >> n >> m;
	
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];	
		}		
	}
	
	int area = 0; 
	int max = 0; 
	int num = 0; 
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			
			if(chk[i][j] || arr[i][j]==0)
				continue;
				
			chk[i][j] = 1;
			Q.push({i,j});
			area = 0;
			num++;
			
			while(!Q.empty()){
				pair<int,int> cur = Q.front();
				Q.pop();
				
				area++;
				
				for(int dir=0; dir<4; dir++){
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					
					if(nx < 0 || nx >= n || ny < 0 || ny >=m)
						continue;
						
					if(chk[nx][ny] || arr[nx][ny]==0)
						continue;
					
					chk[nx][ny]=1;
					Q.push({nx,ny});
				}
				
				if(max < area)
					max = area;
				
			}
		}
	}
	
	cout << num << "\n" << max;
	
	return 0; 
}

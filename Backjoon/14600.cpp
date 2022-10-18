#include <iostream>
#include <cmath>
#define MAX_SIZE 4


using namespace std;

int k, x, y;
int tile[MAX_SIZE][MAX_SIZE];
int num;

int wh;

void divide(int x1, int y1, int x2, int y2, int n) {
	if (n == 2) {
		int paint = 0;
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				if (tile[j][i] == 0) {
					tile[j][i] = num;
					paint++;
				}
			}
		}
		if (paint == 3) num++;
	}
	else {
		int mid_x = (x1 + x2) / 2;
		int mid_y = (y1 + y2) / 2;
		for (int i = mid_y - 1; i < mid_y + 1; i++) {
			for (int j = mid_x - 1; j < mid_x + 1; j++) {
				if (tile[i][j] == 0) {
					tile[i][j] = num;
				}
			}
		}
		num++;
		divide(x1, y1, mid_x, mid_y, n / 2);
		divide(mid_x, mid_y, x2, y2, n / 2);
		divide(mid_x, y1, x2, mid_y, n/2);
		divide(x1, mid_y, mid_x, y2, n / 2);
		return;
	}
}

/*
	좌표
	y,x
	0,0 -> 4,0
	3,3 -> 1,4;
	3,0 -> 1,1
	0,3 -> 4,4
	2,2 -> 2,3
	
	y좌표 -> 4-y
	x좌표 -> x-1

	2,2의 1,2,3,4 어디에 있는지 파악
*/
int main() {
	cin >> k;
	cin >> x >> y;
	int size = pow(2, k);
	y = size - y;
	x = x - 1;
	tile[y][x] = -1;
	num++;
	if (k == 1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++)
				if (tile[i][j] != -1) {
					tile[i][j] = 1;
			}
		}
	}
	else {
		if(x%2==0 && y%2==0){
			tile[y][x+1] = num;
			tile[y+1][x] = num;
			tile[y+1][x+1] = num;
			num++;
		}
		else if (x % 2 == 0 && y % 2 == 1) {
			tile[y-1][x+1] = num;
			tile[y-1][x] = num;
			tile[y][x + 1] = num;
			num++;
		}
		else if (x % 2 == 1 && y % 2 == 0) {
			tile[y+1][x-1] = num;
			tile[y + 1][x] = num;
			tile[y + 1][x + 1] = num;
			num++;
		}
		else {
			tile[y][x - 1] = num;
			tile[y-1][x-1] = num;
			tile[y-1][x] = num;
			num++;
		}
		divide(0,0, size, size, size);
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << tile[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}

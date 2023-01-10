#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

int N;
int map[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> N;
	char k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> k;
			if (k == '.') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	int cnt_row = 0;
	int row = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1)cnt_row++;
			else cnt_row = 0;

			if (cnt_row == 2)
				row ++;
		}
		cnt_row = 0;
	}


	int col = 0;
	int cnt_col = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 1)cnt_col++;
			else cnt_col = 0;

			if (cnt_col== 2)
				col++;
		}

		cnt_col = 0;
	}


	cout << row << " " << col;

	return 0;
}
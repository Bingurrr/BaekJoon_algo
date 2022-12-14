#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

bool is_d(int x1, int y1, int p1, int q1, int x2, int y2, int p2, int q2)
{
	if (p1 < x2 || p2<x1) {
		return 1;
	}
	if (q2 < y1 || q1<y2) {
		return 1;
	}
	return 0;
}
bool is_c(int x1, int y1, int p1, int q1, int x2, int y2, int p2, int q2)
{
	if (p1 == x2 && q1 == y2) {
		return 1;
	}
	if (p2 == x1 && q2 == y1) {
		return 1;
	}
	if (p1 == x2 && y1 == q2) {
		return 1;
	}
	if (x1 == p2 && q1 == y2) {
		return 1;
	}
	return 0;
}
bool is_b(int x1, int y1, int p1, int q1, int x2, int y2, int p2, int q2)
{
	if (p1 == x2) {
		if (q2 > y1 && y2 < q1) {
			return 1;
		}
	}
	if (y1 == q2) {
		if (x1 < p2 && x2 < p1) {
			return 1;
		}
	}
	if (x1 == p2) {
		if (q2 > y1 && q1 > y2) {
			return 1;
		}
	}
	if (q1 == y2) {
		if (x1 < p2 && x2 < p1) {
			return 1;
		}
	}
	return 0;
}
void solve(int x1, int y1, int p1, int q1, int x2, int y2, int p2, int q2)
{
	if (is_d(x1, y1, p1, q1, x2, y2, p2, q2)) {
		cout << "d\n";
	}
	else if (is_c(x1, y1, p1, q1, x2, y2, p2, q2)) {
		cout << "c\n";
	}
	else if (is_b(x1, y1, p1, q1, x2, y2, p2, q2)) {
		cout << "b\n";
	}
	else {
		cout << "a\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x1, y1, p1, q1, x2, y2, p2, q2;
	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;
		solve(x1, y1, p1, q1, x2, y2, p2, q2);
	}
	return 0;
}
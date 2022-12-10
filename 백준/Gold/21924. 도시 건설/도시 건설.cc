#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Start, End, Cost;
};

int N, M;
vector<INFO> Edge;
int Parent[MAX];
LL All_Cost = 0;
LL answer = 0;

void Init() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}
}

bool Comp(INFO A, INFO B) {
	return (A.Cost < B.Cost);
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union(int X, int Y) {
	int PX = Find(X);
	int PY = Find(Y);
	if (PX < PY) {
		Parent[PY] = PX;
	}
	else {
		Parent[PX] = PY;
	}
}

bool isConnected() {
	for (int i = 2; i <= N; i++) {
		if (Find(1) != Find(i)) {
			return false;
		}
	}
	return true;
}

void Input() {
	cin >> N >> M;
	Init();
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		Edge.push_back({ A,B,C });
		All_Cost += C;
	}
}

void Settings() {
	sort(Edge.begin(), Edge.end(), Comp);
	for (int i = 0; i < Edge.size(); i++) {
		int S = Edge[i].Start;
		int E = Edge[i].End;
		int C = Edge[i].Cost;
		if (Find(S) != Find(E)) {
			Union(S, E);
			answer += C;
		}
	}
}

void Find_Answer() {
	if (isConnected()) {
		cout << All_Cost - answer << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}
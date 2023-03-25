#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#define INF 1000002

using namespace std;

struct net {
	int x, y, r;
};
net tmp;
int num;
int parent[3000];
int test, x, y, r;
int x_1,y_1,r_1,x_2,y_2,r_2;
long long dist1, dist2;

int find_parent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find_parent(parent[x]);
}

void uni(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);
	if (pa != pb) parent[pa] = pb;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> test;
	for (int t = 0; t < test; t++) {
		vector<net> v;
		cin >> num;
		for (int i = 0; i < num; i++) {
			parent[i] = i;
			cin >> x >> y >> r;
			tmp.x = x;
			tmp.y = y;
			tmp.r = r;
			v.push_back(tmp);
		}
		int result = num;
		for (int i = 0; i < num - 1; i++)
			for (int j = i + 1; j < num; j++) {
				x_1 = v[i].x;
				y_1 = v[i].y;
				r_1 = v[i].r;
				x_2 = v[j].x;
				y_2 = v[j].y;
				r_2 = v[j].r;
				dist1 = (r_1 + r_2)*(r_1 + r_2);		
				dist2 = (x_1 - x_2)*(x_1 - x_2) + (y_1 - y_2)*(y_1 - y_2);		
				if (dist1 >= dist2 && find_parent(i) != find_parent(j)) {		
					uni(i, j);
					result--;
				}
			}
		cout << result << '\n';
	}
	return 0;
}

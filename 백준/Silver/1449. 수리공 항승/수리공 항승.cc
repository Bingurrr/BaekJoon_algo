#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 2000000001

using namespace std;
            
int location[1001];  
int start, tape, N, L = 0;       


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> location[i];
	}	
	sort(location, location + N);	
	start = location[0];
	for (int i = 1; i < N; i++) {	
		if (L <= location[i] - start) {			
			tape++;		
			start = location[i];
		}
	}	
	cout << tape + 1;

	return 0;
}

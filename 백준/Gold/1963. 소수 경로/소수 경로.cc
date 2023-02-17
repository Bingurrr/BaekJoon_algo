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

int n, start_node, end_node;
bool prime[10001];
int visited[10001];

void eratos() {
    for(int i=2; i*i< 10001; i++){
        for(int j=i*i; j< 10001; j+=i){
            prime[j] = false;
        }
    }
}

int to_int(string num){
    int ret = 0;

    for(int i=0; i<4; i++){
        ret = ret * 10 + (num[i] - '0');
    }

    return ret;
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            string node_s = to_string(node);
            for(int j=0; j<10; j++){
                node_s[i] = j + '0';
                int next = to_int(node_s);
                if(next >= 1000 && prime[next] == true && visited[next] == -1){
                    visited[next] = visited[node] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    memset(prime, true, sizeof(prime));
    eratos();
    
    cin >> n;

    while(n--){
        memset(visited, -1, sizeof(visited));
        cin >> start_node >> end_node;
        bfs(start_node);
        if(visited[end_node] != -1){
            cout << visited[end_node] << '\n';
        }

        else{
            cout << "Impossible" << '\n';
        }
    }


	return 0; 
}

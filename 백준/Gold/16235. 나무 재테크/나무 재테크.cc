#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#define INF 2000000001

using namespace std;

struct tree{
    int r,c,age;
    tree(int R, int C, int AGE) : r(R), c(C), age(AGE) {};
};

int n, m, k, ans;
int water[11][11];
int A[11][11];
vector<int> arr[11][11];
int x, y, z;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    queue<tree> trees;  
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> A[i][j];
            water[i][j] = 5;
        }
    }
    
    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        arr[x][y].push_back(z);
    }
    while(k > 0){
        // cout << arr[1][1][0] << endl;
        k--;
        queue<tree> dead_trees; // 죽는 나무
        queue<tree> parent_trees; // 번식 하는 나무
        
        // 1 step
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][j].size() > 0){
                    // 어린 나이 순으로 정렬 우선 순위 큐
                    vector<int> new_trees;
                    sort(arr[i][j].begin(), arr[i][j].end());
                    for(int a = 0; a < arr[i][j].size(); a++){
                        // 물주기
                        if(arr[i][j][a] <= water[i][j]){
                            water[i][j] -= arr[i][j][a];
                            arr[i][j][a]++;
                            new_trees.push_back(arr[i][j][a]);
                            //번식하는 나무 추가
                            if(arr[i][j][a] % 5 == 0){
                                parent_trees.push({i,j,a});
                            }
                        }
                        // 죽은 나무
                        else {
                            dead_trees.push({i,j,arr[i][j][a]});
                            // cout << "dead trees" << endl;
                            // cout << i << " " << j << " " << arr[i][j][a] << endl;
                        }
                    }
                    arr[i][j] = new_trees;
                }
            }
        }

        // 2 step -> 죽은 나무 양분
        while(!dead_trees.empty()){
            int a = dead_trees.front().r;
            int b = dead_trees.front().c;
            water[a][b] += dead_trees.front().age/2;
            // cout << "step 2" << endl;
            // cout << a << " " << b << " " << dead_trees.front().age/2 << endl;
            dead_trees.pop();
        }        

        // 3 step -> 번식하는 나무
        while(!parent_trees.empty()){
            int a = parent_trees.front().r;
            int b = parent_trees.front().c;
            int c = parent_trees.front().age;
            parent_trees.pop();

            if(a -1 >= 1){
                arr[a-1][b].push_back(1);
                if(b-1 >= 1){
                    arr[a-1][b-1].push_back(1);
                }
                if(b+1 <= n){
                    arr[a-1][b+1].push_back(1);
                }
            }
            if(b -1 >= 1){
                arr[a][b-1].push_back(1);
            }
            if(a+1 <= n){
                arr[a+1][b].push_back(1);
                if(b+1 <= n){
                    arr[a+1][b+1].push_back(1);
                }
                if(b-1 >= 1){
                    arr[a+1][b-1].push_back(1);
                }
            }
            if(b+1 <= n){
                arr[a][b+1].push_back(1);
            }
        }

        // 4 step -> 양분 추가
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                water[i][j] += A[i][j];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // cout << arr[i][j].size() << " ";
            ans += arr[i][j].size();
        }
        // cout << endl;
    }
    cout << ans;
    
	return 0;
}

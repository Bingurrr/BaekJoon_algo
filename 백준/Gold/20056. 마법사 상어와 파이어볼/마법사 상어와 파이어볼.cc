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

struct fireball{
    int r,c,m,s,d;
    fireball(int R, int C, int M, int S, int D) : r(R), c(C), m(M), s(S), d(D) {};
};

long long int ans;
int n, M, k;
int r, c, m, s, d;
int direction[8][2] = {{-1,0},{-1,1},{0,1},
                        {1,1},{1,0},{1,-1},
                        {0,-1},{-1,-1}};
queue<fireball> q;
// vector<fireball> arr[51][51];
// 파이어볼 이동
// 합쳐짐
// 나눠짐
// 소멸

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    

    cin >> n >> M >> k;

    for(int i = 0; i < M; i++){
        cin >> r >> c >> m >> s >> d;
        q.push(fireball({r,c,m,s,d}));
    }

    while(k > 0){
        vector<fireball> arr[51][51];
        k--;
        // 1단계
        while(!q.empty()){
            // cout << q.front().r << " " << q.front().c << " " << q.front().s << " " << q.front().d << endl;
            int a = q.front().r+((q.front().s*direction[q.front().d][0])%n);
            int b = q.front().c+((q.front().s*direction[q.front().d][1])%n);
            // cout << a << " " << b << endl;
            if(a > n){
                a -= n;
            }
            else if(a < 1){
                a += n;
            }
            if(b > n){
                b -= n;
            }
            else if(b < 1){
                b += n;
            }
            // cout << a << " " << b << endl;
            arr[a][b].push_back(fireball({a,b,q.front().m,q.front().s,q.front().d}));
            q.pop();
        }
        // 2단계
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){   
                // 2개이상
                if(arr[i][j].size() >=2){
                    // cout << " aa  " << endl;
                    int sum_m = 0;
                    int sum_s = 0;
                    int dire = arr[i][j][0].d%2;
                    bool ch = false;
                    for(auto ball : arr[i][j]){
                        sum_m += ball.m;
                        sum_s += ball.s;
                        if(ch == false && dire != ball.d%2){
                            ch = true;
                        }
                    }
                    sum_m /= 5;
                    sum_s /= arr[i][j].size();
                    // cout << "sum: " <<  sum_m << " " << sum_s << endl;
                    if(sum_m > 0){
                        if(ch == true){
                            q.push({i,j,sum_m,sum_s,1});
                            q.push({i,j,sum_m,sum_s,3});
                            q.push({i,j,sum_m,sum_s,5});
                            q.push({i,j,sum_m,sum_s,7});
                        }
                        else{
                            q.push({i,j,sum_m,sum_s,0});
                            q.push({i,j,sum_m,sum_s,2});
                            q.push({i,j,sum_m,sum_s,4});
                            q.push({i,j,sum_m,sum_s,6});
                        }
                    }
                }
                else if(arr[i][j].size() == 1){
                    // cout << i << " " << j << endl;
                    q.push(arr[i][j][0]);
                }
            }
        }

    }
    while(!q.empty()){
        ans += q.front().m;
        q.pop();
    }
    cout << ans << endl;
	return 0;
}

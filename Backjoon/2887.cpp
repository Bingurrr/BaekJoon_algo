#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>

using namespace std;

int getParent(int parent[], int x){
    if(parent[x] == x ) return x;
    return parent[x] = getParent(parent, parent[x]);
};

void unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b ) parent[b] = a;
    else parent[a] = b;
};

int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if( a == b ) return 1;
    return 0;
};

class Edge{
public:
    int a;
    int b;
    int distance;
    Edge(int a, int b, int distance){
        this->a = a;
        this->b = b;
        this->distance = distance;
    }
    bool operator <(Edge &edge){
        return this->distance < edge.distance;
    }
};

int main(){
    int n, x, y, z;
    int ans = 0;
    cin >> n;
    vector<pair<int,int>> X;
    vector<pair<int,int>> Y;
    vector<pair<int,int>> Z;
    vector<tuple<int,int,int>> planet;
    int parent[n];
    for(int i = 0; i < n; i++){
        parent[i] = i;
        cin >> x >> y >> z;
        X.push_back({x,i});
        Y.push_back({y,i});
        Z.push_back({z,i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for(int i = 0; i < n-1; i++){
        planet.push_back({X[i+1].first-X[i].first, X[i].second, X[i+1].second});
        planet.push_back({Y[i+1].first-Y[i].first, Y[i].second, Y[i+1].second});
        planet.push_back({Z[i+1].first-Z[i].first, Z[i].second, Z[i+1].second});
    }
    sort(planet.begin(), planet.end());
    for(unsigned int i = 0; i < planet.size(); i++){
        int d = get<0>(planet[i]);
        int u = get<1>(planet[i]);
        int v = get<2>(planet[i]);
        if(!findParent(parent, u, v)){
            ans += d;
            unionParent(parent, u, v);
        }
    }

    cout << ans;

    return 0;
}

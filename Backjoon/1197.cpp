#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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
    int v;
    int e;
    cin >> v >> e;
    int a,b,d;
    int ans = 0;
    set<int> s;
    vector<Edge> ve;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> d;
        ve.push_back(Edge(a,b,d));
    }
    sort(ve.begin(), ve.end());

    int parent[v];
    for(int i = 0; i < v; i++){
        parent[i] = i;
    }
    for(int i = 0; i < ve.size(); i++){
        if(!findParent(parent, ve[i].a -1, ve[i].b -1)){
            ans += ve[i].distance;
            unionParent(parent, ve[i].a-1, ve[i].b-1);
        }
    }

    cout << ans;

    return 0;
}

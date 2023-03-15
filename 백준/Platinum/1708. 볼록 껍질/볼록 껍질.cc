#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#define INF 987654321

using namespace std;

struct pos {
    long long x,y;
};

vector <pos> v;
stack <pos> s;
int t;
long long ccw(pos a, pos b, pos c) { 
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

bool cmp(pos a, pos b){
    long long int cc = ccw(v[0], a, b);
    if (cc)
        return cc>0;
    else if (a.y != b.y)
        return a.y < b.y;
    else 
        return a.x < b.x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    
    v.resize(t);
    for (int i=0; i<t; i++){
        cin>>v[i].x>>v[i].y;
    }
    
    for (int i=1; i<t; i++){
        if(v[i].y < v[0].y || (v[i].y == v[0].y && v[i].x < v[0].x)){
            
            long long temp = v[0].x;
            v[0].x = v[i].x;
            v[i].x = temp;
            
            temp = v[0].y;
            v[0].y = v[i].y;
            v[i].y = temp;
        }
    }
    
    sort(v.begin()+1, v.end(), cmp);
    s.push(v[0]);
    s.push(v[1]);
    for(int i = 2; i<t; i++){
        while (s.size() >= 2){
            pos top2 = s.top();
            s.pop();
            pos top1 = s.top();
            if (ccw(top1, top2, v[i]) > 0){
                s.push(top2); 
                break;
            }
        }
        s.push(v[i]);
    }
    cout << s.size();
    return 0;
}

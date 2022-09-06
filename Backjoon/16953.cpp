#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long rule1(long long num) {
    return num*2;
}
long long rule2(long long num) {
    return num*10 + 1;
}


int main (void){
    queue<long long> q;
    queue<long long> q_cnt;
    long long a,b;
    long long n1;
    long long n2;
    long long cnt;
    cin >> a >> b;
    if (rule1(a) == b || rule2(a) == b){
        cout << 2;
        return 0;
    }
    q.push(rule1(a));
    q.push(rule2(a));
    q_cnt.push(2);
    q_cnt.push(2);
    long long n = a;
    long long answer = -1;
    while(q.size() != 0){
        n = q.front();
        cnt = q_cnt.front();
        n1 = rule1(n);
        n2 = rule2(n);
        //cout << n1 << " " << n2 << " " << cnt << endl;
        if (n1 == b || n2 == b){
            answer = cnt+1;
            break;
        }
        if (n1 < b) {
            q.push(n1);
            q_cnt.push(cnt+1);
        }
        if (n2 < b){
            q.push(n2);
            q_cnt.push(cnt+1);
        }
        q.pop();
        q_cnt.pop();
    }
    cout << answer;
    return 0;
}

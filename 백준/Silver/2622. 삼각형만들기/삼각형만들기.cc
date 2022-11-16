#include<iostream>
using namespace std;
 
int n, cnt;
 
//입력
void input(){
    cin >> n;
}
 
void solution(){
    
    for(int a=1; a<n; a++){    
        for(int b=a; b<n; b++){ 
            int c = n-(a+b);
            if(c < b) break;    
            if(b+a > c) cnt++;  
        }
    }
    
}
void output(){
    cout << cnt ;
}
 
int main(void){
    input();
    solution();
    output();
    return 0;
}
 
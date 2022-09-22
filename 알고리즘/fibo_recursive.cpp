#include <iostream>

using namespace std;

int a1[4] = {1,1,1,0};

int fibo(int a){
    if(a==0) {
        return 0;
    }
    else if (a == 1){
        return 1;
    }
    else {
        return fibo(a-1) + fibo(a-2);
    }
    
}

int main(){
    int n;
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        cout << fibo(num) << endl;
    }
}

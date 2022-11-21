#include <iostream>
using namespace std;

bool flag = false;
int arr[10][10];
bool pro(int x, int y, int a){	
	for(int i=0; i<9; i++){
		if(arr[x][i]==a) return false;
		if(arr[i][y]==a) return false;
	}
	for(int i=(x/3)*3; i<(x/3)*3+3; i++){
		for(int j=(y/3)*3; j<(y/3)*3+3; j++)
			if(arr[i][j]==a) return false;
	}
	return true;
}

void solve(int x, int y){
    if(flag==true) return;
    if(x==9){
        flag = true;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << arr[i][j];
            }
            cout << '\n';
        }
        return;
    }
    if(y==9){
        solve(x+1,0);
    }
    if(arr[x][y] == 0){
        for(int i = 1; i<=9; i++){
            if(pro(x,y,i)){
                arr[x][y] = i;
                solve(x,y+1);
                arr[x][y]=0;
            }
        }
    }
    else solve(x,y+1);   
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char s;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> s;
            arr[i][j] = s-'0';
        }
        // cout << endl;
    }
    solve(0,0);
    return 0;
}
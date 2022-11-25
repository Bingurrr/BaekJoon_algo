
#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    string str;
 
    int cnt=0;
 
    for(int i=1; i<=8; i++){
        cin>>str;
        int len=str.length();
        for(int j=0; j<len; j++){
            if(i%2==0){
                if(j%2!=0){
                    if(str[j]=='F'){
                        cnt++;
                    }
                }
            }
            else{
                if(j%2==0){
                    if(str[j]=='F'){
                        cnt++;
                    }
                }
            }
        }
    }
 
    cout<<cnt;
}

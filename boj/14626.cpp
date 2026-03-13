#include <bits/stdc++.h>
using namespace std;
int check, temp, flag;
string s;

void solve(){
    cin >> s;
    for(int i=0; i<s.size(); i++, flag ^= 1){
        if(s[i] == '*') check = (flag ? 3 : 1);
        else temp += (flag ? (s[i]-'0') * 3 : (s[i] - '0'));
    }
    for(int i=0; i<10; i++){
        if((temp + i*check)%10 == 0){
            cout << i;
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
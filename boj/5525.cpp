#include <bits/stdc++.h>
using namespace std;
int n,m,ret;
string s;

void solve(){
    cin >> n >> m >> s;

    for(int i=0; i<s.size(); i++){
        if(s[i] == 'O') continue;
        int temp = 0;
        for(int idx = i; idx < s.size()-2; idx += 2){
            if(s[idx+1] == 'O' && s[idx+2] == 'I') temp++;
            else break;
            i = idx;
        }
        if(temp >= n) ret += temp - n + 1;
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
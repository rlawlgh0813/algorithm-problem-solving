#include <bits/stdc++.h>
using namespace std;
int ret;

void go(string s){
    if(s.size() == 1){
        ret++;
        return;
    }
    string l = s.substr(1);
    string r = s.substr(0,s.size()-1);
    if(l == r){
        ret++;
        return;
    }
    go(l);
    go(r);
}

void solve(){
    string s; cin >> s;
    go(s);

    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
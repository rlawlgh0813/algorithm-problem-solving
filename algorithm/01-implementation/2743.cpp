#include <bits/stdc++.h>
using namespace std;
long long a,b;

void solve(){
    for(int i=0; i<4; i++){
        long long t; cin >> t;
        a += t;
    }
    for(int i=0; i<4; i++){
        long long t; cin >> t;
        b += t;
    }
    if(a > b) cout << a;
    else cout << b;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
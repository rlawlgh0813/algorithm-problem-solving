#include <bits/stdc++.h>
using namespace std;
#define MOD 1234567891
int t;
long long r = 31,ret;
string s;

void solve(){
    cin >> t >> s;
    for(int i=0; i<t; i++){
        long long a = s[i] - 'a' + 1;
        for(int j=0; j<i; j++) a = (a * r) % MOD;
        ret = (ret + a) % MOD;
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
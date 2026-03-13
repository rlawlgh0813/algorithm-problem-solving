#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
typedef long long ll;
typedef vector<vector<long long>> vvll;
int n;
vector<vector<ll>> v = {
    {0,1,1,0,0,0,0,0},
    {1,0,1,1,0,0,0,0},
    {1,1,0,1,1,0,0,0},
    {0,1,1,0,1,1,0,0},
    {0,0,1,1,0,1,1,0},
    {0,0,0,1,1,0,0,1},
    {0,0,0,0,1,0,0,1},
    {0,0,0,0,0,1,1,0},
};

vvll go(vvll a, vvll b){
    vvll ret(8, vector<ll>(8,0));
    for(int i=0; i<8; i++) for(int j=0; j<8; j++) for(int k=0; k<8; k++) ret[i][j] = (ret[i][j] + a[i][k]*b[k][j]) % MOD;
    return ret;
}

void solve(){
    cin >> n;
    
    vvll ret(8, vector<ll>(8,0));
    for(int i=0; i<8; i++) ret[i][i] = 1;

    while(n > 0){
        if(n & 1) ret = go(ret, v);
        v = go(v,v);
        n /= 2;
    }
    cout << ret[0][0];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
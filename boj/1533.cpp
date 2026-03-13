#include <bits/stdc++.h>
using namespace std;
#define MOD 1000003
typedef vector<vector<long long>> vvll;
int n,s,e,t;

vvll go(vvll a, vvll b){
    vvll ret(55, vector<long long>(55,0));
    for(int i=0; i<55; i++) for(int j=0; j<55; j++) for(int k=0; k<55; k++) ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
    return ret;
}

void solve(){
    cin >> n >> s >> e >> t;
    
    vvll map(55,vector<long long>(55,0));
    for(int i=1; i<=n; i++){
        string s; cin >> s;
        for(int j=0; j<s.size(); j++) if(s[j] != '0') map[i*5][(j+1)*5 - (s[j]-'0'-1)] = 1;
        for(int j=1; j<5; j++) map[(i-1)*5 + j][(i-1)*5 + j+1] = 1;
    }

    vvll ret(55,vector<long long>(55,0));
    for(int i=0; i<55; i++) ret[i][i] = 1;
    while(t > 0){
        if(t & 1) ret = go(ret, map);
        map = go(map,map);
        t /= 2;
    }
    cout << ret[s*5][e*5];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
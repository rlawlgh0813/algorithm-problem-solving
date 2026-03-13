#include <bits/stdc++.h>
using namespace std;
#define INF 1000004
int n,m,ret;
int a[1000004];

void solve(){
    cin >> n >> m;

    for(int i=2; i<sqrt(INF); i++){
        if(a[i]) continue;
        for(int j=i*2; j<=INF; j+=i) a[j] = 1;
    }
    for(int i=n; i<=m; i++) if(!a[i] && i != 1) cout << i << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
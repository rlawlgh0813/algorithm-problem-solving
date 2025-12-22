#include <bits/stdc++.h>
using namespace std;
int n,m,flag;
int dp[10004];

void solve(){
    int p,q; scanf("%d %d.%d",&n,&p,&q); m = p*100+q;
    if(n == 0){ flag = 1; return; }
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<n; i++){
        int c,p,u,v; scanf("%d %d.%d",&c,&u,&v); p = u*100+v;
        for(int j=p; j<=m; j++) dp[j] = max(dp[j], dp[j-p] + c);
    }

    cout << dp[m] << '\n';
}

int main(){
    ios::sync_with_stdio(0);

    while(!flag) solve();
    return 0;
}
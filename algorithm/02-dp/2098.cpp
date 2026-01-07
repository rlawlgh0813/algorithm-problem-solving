#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int n;
int val[20][20], dp[20][1<<20];

int go(int cur, int vis){
    if(vis == (1<<n)-1) return val[cur][0] ? val[cur][0] : INF;

    int &ret = dp[cur][vis];
    if(ret != -1) return ret;
    ret = INF;

    for(int i=0; i<n; i++){
        if((vis & (1<<i)) || val[cur][i] == 0) continue;
        ret = min(ret, go(i, vis|(1<<i)) + val[cur][i]);
    }
    return ret;
}

void solve(){ 
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> val[i][j];
    memset(dp, -1, sizeof(dp));

    cout << go(0,1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
} 
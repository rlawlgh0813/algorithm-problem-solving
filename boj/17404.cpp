#include <bits/stdc++.h>
using namespace std;
int n, ret = 1e9;
int val[1004][4], vis[1004];

void go(int here, int cnt){
    if(here > n){
        ret = min(ret, cnt);
        return;
    }

    for(int i=1; i<=3; i++){
        if(here == n && i == vis[1]) continue;
        if(i == vis[here-1]) continue;
        vis[here] = i;
        go(here+1,cnt+val[here][i]);
        vis[here] = 0;
    }
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=3; j++) cin >> val[i][j];

    go(1,0);
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}
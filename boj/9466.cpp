#include <bits/stdc++.h>
using namespace std;
int n,ret;
int a[100004], vis[100004];

int go(int here, int start){
    if(vis[here]){
        if(here == start) return 2;
        return 1;
    }
    vis[here] = 1;

    return vis[here] = go(a[here], start);
}

void solve(){
    cin >> n;
    memset(vis, 0, sizeof(vis));
    ret = 0;
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n; i++){
        vis[i] = go(i,i);
        for(int j=1; j<=n; j++) cout << vis[j];
        cout << '\n';
    }
    for(int i=1; i<=n; i++) if(vis[i] != 2) ret++;
    
    cout << ret << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) solve();
    
    return 0;
}
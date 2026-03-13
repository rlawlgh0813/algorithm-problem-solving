#include <bits/stdc++.h>
using namespace std;
int n,ret;
int a[100004], vis[100004], check[100004];

void go(int here){
    vis[here] = 1;
    int there = a[here];

    if(!vis[there]) go(there);
    else if(!check[there]){
        for(int i=there; i != here; i = a[i]) ret--;
        ret--;
    }
    check[here] = 1;
}

void solve(){
    cin >> n;
    memset(vis, 0, sizeof(vis));
    memset(check, 0, sizeof(check));
    ret = n;  
    for(int i=1; i<=n; i++) cin >> a[i];

    for(int i=1; i<=n; i++) if(!vis[i]) go(i);
    cout << ret << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) solve();
    
    return 0;
}
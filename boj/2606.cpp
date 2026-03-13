#include <bits/stdc++.h>
using namespace std;
int n,m,ret;
int vis[104];
vector<int> v[104];

void go(int here){
    vis[here] = 1;

    int ret = 1;
    for(auto there : v[here]){
        if(vis[there]) continue;
        ret++;
        go(there);
    }
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    go(1);
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
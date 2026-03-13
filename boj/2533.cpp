#include <bits/stdc++.h>
using namespace std;
int n;
int ret[2], vis[1000004];
vector<int> adj[1000004];

void go(int here, int parent){
    vis[here] = 1;
    
    int isRoot = 0;
    for(auto there : adj[here]){
        if(there == parent || vis[there]) continue;
        go(there, here);
        isRoot = 1;
    }
    if(isRoot)
}

void solve(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        int p,q; cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    go(1,0);

    cout << ret[0] << " " << ret[1] << '\n';
    cout << min(ret[0],ret[1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,m;
int parent[100004], dep[100004], vis[100004];
vector<int> adj[100004];

void go(int here, int depth){
    vis[here] = 1;
    dep[here] = depth;
    for(auto there : adj[here]){
        if(there == parent[here] || vis[there]) continue;
        parent[there] = here;
        go(there, depth+1);
    }
}

void solve(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        int p,q; cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    go(1,1);

    cin >> m;
    while(m--){
        int p,q; cin >> p >> q;
        if(dep[p] > dep[q]) swap(p,q);
        while(dep[p] != dep[q]) q = parent[q];
        while(p != q){
            p = parent[p];
            q = parent[q];
        }
        cout << p << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
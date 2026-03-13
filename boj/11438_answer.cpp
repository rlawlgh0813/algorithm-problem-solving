#include <bits/stdc++.h>
using namespace std;
#define MAX 100004
#define LOG 17
int n,m;
int parent[MAX][LOG], dep[MAX], vis[MAX];
vector<int> adj[100004];

void go(int here, int depth){
    vis[here] = 1;
    dep[here] = depth;
    for(auto there : adj[here]){
        if(there == parent[here][0] || vis[there]) continue;
        parent[there][0] = here;
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
    for(int i=1; i<LOG; i++) for(int j=1; j<=n; j++) parent[j][i] = parent[parent[j][i-1]][i-1];

    cin >> m;
    while(m--){
        int p,q; cin >> p >> q;
        if(dep[p] > dep[q]) swap(p,q);
        for(int i=LOG-1; i>=0; i--) if(dep[q] - dep[p] >= (1<<i)) q = parent[q][i];
        if(p == q) cout << p << '\n';
        else{
            for(int i=LOG-1; i>=0; i--){
                if(parent[p][i] == parent[q][i]) continue;
                p = parent[p][i];
                q = parent[q][i];
            }
            cout << parent[p][0] << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
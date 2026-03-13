#include <bits/stdc++.h>
using namespace std;
int n,m;
int vis[10004], parent[10004];
vector<int> v[10004], ret;

int Find(int n){
    if(n == parent[n]) return n;
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) parent[b] = a;
}

void go(int here, int prev){
    vis[here] = 1;

    int check = 0;
    for(auto there : v[here]){
        if(vis[there] || there == prev) continue;
        go(there, here);
        check = 1;
    }
    if(prev && check) ret.push_back(here);
}

void solve(){
    cin >> n >> m;

    for(int i=1; i<=n; i++) parent[i] = i;
    while(m--){
        int p,q; cin >> p >> q;
        if(Find(p) != Find(q)){
            v[p].push_back(q);
            v[q].push_back(p);
            Union(p,q);
        }
    }

    for(int i=1; i<=n; i++) if(!vis[i]) go(i,0);

    cout << ret.size() << '\n';
    for(auto x : ret) cout << x << " ";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
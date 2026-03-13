#include <bits/stdc++.h>
using namespace std;
int n,m;
int parent[40004], dist[40004], dep[40004];
vector<pair<int,int>> v[40004];

void go(int here, int prev, int depth, int weight){
    parent[here] = prev;
    dep[here] = depth;
    dist[here] = weight;

    for(auto there : v[here]){
        if(there.first == prev) continue;
        go(there.first, here, depth+1, there.second + weight);
    }
}

void solve(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        int p,q,w; cin >> p >> q >> w;
        v[p].push_back({q,w});
        v[q].push_back({p,w});
    }
    go(1,1,1,0);

    cin >> m;
    for(int i=0; i<m; i++){
        int p,q; cin >> p >> q;
        int ret = dist[p] + dist[q];
        if(dep[p] < dep[q]) swap(p,q);
        while(dep[p] > dep[q]) p = parent[p];
        while(p != q){
            p = parent[p];
            q = parent[q];
        }
        cout << ret - (dist[p] * 2) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
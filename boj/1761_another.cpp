#include <bits/stdc++.h>
using namespace std;
#define MAX_LOG 20
int n,m;
int parent[40004][MAX_LOG], dist[40004][MAX_LOG], dep[40004];
vector<pair<int,int>> v[40004];

void go(int here, int prev, int depth, int weight){
    parent[here][0] = prev;
    dep[here] = depth;
    dist[here][0] = weight;

    for(auto there : v[here]){
        if(there.first == prev) continue;
        go(there.first, here, depth+1, there.second);
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
    for(int i=1; i<MAX_LOG; i++){
        for(int j=1; j<=n; j++){
            int mid = parent[j][i-1];
            parent[j][i] = parent[mid][i-1];
            dist[j][i] = dist[j][i-1] + dist[mid][i-1];
        }
    }

    cin >> m;
    for(int i=0; i<m; i++){
        int p,q,ret = 0; cin >> p >> q;
        if(dep[p] < dep[q]) swap(p,q);
        for(int j = MAX_LOG-1; j >= 0; j--){
            if(dep[p] - (1<<j) >= dep[q]){
                ret += dist[p][j];
                p = parent[p][j];
            }
        }
        if(p != q){
            for(int j = MAX_LOG-1; j >= 0; j--){
                if(parent[p][j] != 0 && parent[p][j] != parent[q][j]){
                    ret += dist[p][j] + dist[q][j];
                    p = parent[p][j];
                    q = parent[q][j];
                }
            }
            ret += dist[p][0] + dist[q][0];
        }
        cout << ret << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
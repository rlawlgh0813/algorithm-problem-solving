#include <bits/stdc++.h>
using namespace std;
int n,m;
int parent[100004], dist[100004];

int Find(int n){
    if(n == parent[n]) return n;
    int root = Find(parent[n]);
    dist[n] += dist[parent[n]];
    return parent[n] = root;
}

void Union(int a, int b, int val){
    int A = Find(a);
    int B = Find(b);
    if(A != B){
        parent[B] = A;
        dist[B] = dist[a] - dist[b] + val;
    }
}

void solve(){
    char cmd; cin >> cmd;
    if(cmd == '!'){
        int p,q,w; cin >> p >> q >> w;
        Union(p,q,w);
    }else{
        int p,q; cin >> p >> q;
        if(Find(p) != Find(q)) cout << "UNKNOWN" << '\n';
        else cout << dist[q] - dist[p] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i=1; i<=n; i++){
            parent[i] = i;
            dist[i] = 0;
        }
        while(m--) solve();
    }
    return 0;
}
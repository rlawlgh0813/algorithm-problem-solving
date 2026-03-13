#include <bits/stdc++.h>
using namespace std;
int n,m,ret;
int parent[10004];

struct cmp{
    bool operator()(tuple<int,int,int> a, tuple<int,int,int> b){
        return get<2>(a) > get<2>(b);
    }
};
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, cmp> pq;

int Find(int n){
    if(parent[n] == n) return n;
    return parent[n] = Find(parent[n]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    parent[b] = a;
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int p,q,w; cin >> p >> q >> w;
        pq.emplace(p,q,w);
    }
    for(int i=1; i<=n; i++) parent[i] = i;

    while(pq.size()){
        int p,q,w;
        tie(p,q,w) = pq.top(); pq.pop();

        if(Find(p) != Find(q)){
            ret += w;
            Union(p,q);
        }
    }
    cout << ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
    return 0;
}